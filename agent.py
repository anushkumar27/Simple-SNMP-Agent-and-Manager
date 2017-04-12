'''
Create an MIB agent that interacts with another monitor instance
'''

from pysnmp.entity import engine, config
from pysnmp import debug
from pysnmp.entity.rfc3413 import cmdrsp, context, ntforg
from pysnmp.carrier.asynsock.dgram import udp
from pysnmp.smi import builder

import threading
import collections
import time

MibObject = collections.namedtuple('MibObject', ['mibName',
                                   'objectType', 'valueFunc','valueSetFunc'])

class Mib(object):
    """Stores the custom MIB object data 
       Contains getter and setter functions for our custom MIB objects
    """

    def __init__(self):
        self._lock = threading.RLock()
        self._test_count = 0							#testCount object, which is incremented each time a trap is sent by the agent
        self._test_desc = "My Description"				#testDescription object, of type octet string
        self._test_int = 5								#testInteger object, of type Integer32

    """
    testCount has OID 1.3.6.1.4.1.42.1
    testDescription has OID 1.3.6.1.4.1.42.2
    testInteger has OID 1.3.6.1.4.1.42.4
    """

    def getTestDescription(self):
        return self._test_desc

    def getTestCount(self):
        with self._lock:
            return self._test_count

    def setTestCount(self, value):
        with self._lock:
            self._test_count = value

    def setTestDescription(self, value):
    	with self._lock:
    		self._test_desc = value

    def getTestInteger(self):
    	return self._test_int

    def setTestInteger(self, value):
        with self._lock:
            self._test_int = value

def createVariable(SuperClass, getValue, setValue, *args):
    """This is going to create a instance variable that we can export to the monitor. 
    getValue is a function to call to retreive the value of the scalar
    setValue is a function to set the value of a scalar
    """
    class Var(SuperClass):
        def readGet(self, name, *args):
        	print "Getting obj"
        	return name, self.syntax.clone(getValue())

        def writeCommit(self, name, val, *args ):
        	print "Setting obj..."
        	setValue(val)

    return Var(*args)


class SNMPAgent(object):
    """Implements an Agent that serves the custom MIB and
    can send a trap.
    """

    def __init__(self, mibObjects):
        """
        mibObjects - a list of MibObject tuples that this agent
        will serve
        """

        #each SNMP-based application has an engine
        self._snmpEngine = engine.SnmpEngine()

        #open a UDP socket on port 161 to listen for snmp requests
        config.addSocketTransport(self._snmpEngine, udp.domainName,
                                  udp.UdpTransport().openServerMode(('', 161)))

        #Here we configure two distinct Community Strings to control read and write
		#operations. public --> Read only, private --> Read/Write 
        config.addV1System(self._snmpEngine, "agent", "public")
        config.addV1System(self._snmpEngine, 'my-write-area', 'private')
        
        #let anyone accessing 'public' read anything in the subtree below,
        #which is the enterprises subtree that we defined our MIB to be in
        config.addVacmUser(self._snmpEngine, 2, "agent", "noAuthNoPriv",
                           readSubTree=(1,3,6,1,4,1))

        #let anyone accessing 'private' read and write anything in the subtree below,
        #which is the enterprises subtree that we defined our MIB to be in
        config.addVacmUser(self._snmpEngine, 2, 'my-write-area', 'noAuthNoPriv', readSubTree=(1, 3, 6, 1, 4, 1), writeSubTree=(1, 3, 6, 1, 4, 1))

        #Create Agent context
        self._snmpContext = context.SnmpContext(self._snmpEngine)

        #the builder is used to load mibs. tell it to look in the
        #current directory for our new MIB. We'll also use it to
        #export our symbols later
        mibBuilder = self._snmpContext.getMibInstrum().getMibBuilder()
        mibSources = mibBuilder.getMibSources() + (builder.DirMibSource('.'),)
        mibBuilder.setMibSources(*mibSources)
        
        MibScalarInstance, = mibBuilder.importSymbols('SNMPv2-SMI',
                                                      'MibScalarInstance')
        #export our custom mib
        for mibObject in mibObjects:
            nextVar, = mibBuilder.importSymbols(mibObject.mibName,
                                                mibObject.objectType)
            instance = createVariable(MibScalarInstance,
                                      mibObject.valueFunc,
                                      mibObject.valueSetFunc,
                                      nextVar.name, (0,),
                                      nextVar.syntax)
            #need to export as <var name>Instance
            instanceDict = {str(nextVar.name)+"Instance":instance}
            mibBuilder.exportSymbols(mibObject.mibName,
                                     **instanceDict)

        # tell pysnmp to respond to get, set, getnext, and getbulk
        cmdrsp.GetCommandResponder(self._snmpEngine, self._snmpContext)
        cmdrsp.SetCommandResponder(self._snmpEngine,self._snmpContext)
        cmdrsp.NextCommandResponder(self._snmpEngine, self._snmpContext)
        cmdrsp.BulkCommandResponder(self._snmpEngine, self._snmpContext)


    def setTrapReceiver(self, host, community):
        """Send traps to the host using community string public
        """
        config.addV1System(self._snmpEngine, 'nms-area', community)
        config.addVacmUser(self._snmpEngine, 2, 'nms-area', 'noAuthNoPriv',
                           notifySubTree=(1,3,6,1,4,1))
        config.addTargetParams(self._snmpEngine,
                               'nms-creds', 'nms-area', 'noAuthNoPriv', 1)
        config.addTargetAddr(self._snmpEngine, 'my-nms', udp.domainName,
                             (host, 162), 'nms-creds',
                             tagList='all-my-managers')
        #set last parameter to 'notification' to have it send
        #informs rather than unacknowledged traps
        config.addNotificationTarget(
            self._snmpEngine, 'test-notification', 'my-filter',
            'all-my-managers', 'trap')


    def sendTrap(self):
        print "Sending trap"
        ntfOrg = ntforg.NotificationOriginator(self._snmpContext)
        errorIndication = ntfOrg.sendNotification(
            self._snmpEngine,
            'test-notification',
            ('MY-MIB', 'testTrap'),
            ())


    def serve_forever(self):
        print "Starting agent"
        self._snmpEngine.transportDispatcher.jobStarted(1)
        try:
           self._snmpEngine.transportDispatcher.runDispatcher()
        except:
            self._snmpEngine.transportDispatcher.closeDispatcher()
            raise

class Worker(threading.Thread):
    """For updating the MIB and sending traps, maintaining concurrency.
    """

    def __init__(self, agent, mib):
        threading.Thread.__init__(self)
        self._agent = agent
        self._mib = mib
        self.setDaemon(True)

    def run(self):
        while True:
            time.sleep(3)
            self._mib.setTestCount(mib.getTestCount()+1)
            self._agent.sendTrap()

if __name__ == '__main__':
    mib = Mib()
    objects = [MibObject('MY-MIB', 'testDescription', mib.getTestDescription, mib.setTestDescription),
               MibObject('MY-MIB', 'testCount', mib.getTestCount, mib.setTestCount),
               MibObject('MY-MIB', 'testInteger', mib.getTestInteger, mib.setTestInteger)]
    agent = SNMPAgent(objects)
    agent.setTrapReceiver('127.0.0.1', 'traps')
    Worker(agent, mib).start()
    try:
        agent.serve_forever()
    except KeyboardInterrupt:
        print "Shutting down"

