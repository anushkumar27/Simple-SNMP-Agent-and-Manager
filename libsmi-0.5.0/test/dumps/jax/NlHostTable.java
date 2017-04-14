/*
 * This Java file has been generated by smidump 0.4.5. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id: NlHostTable.java 1458 2006-05-29 16:21:11Z strauss $
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table nlHostTable defined in RMON2-MIB.

    @version 1
    @author  smidump 0.4.5
    @see     AgentXTable
 */

import java.util.Vector;

import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXResponsePDU;
import jax.AgentXSetPhase;
import jax.AgentXTable;
import jax.AgentXEntry;

public class NlHostTable extends AgentXTable
{

    // entry OID
    private final static long[] OID = {1, 3, 6, 1, 2, 1, 16, 14, 2, 1};

    // constructors
    public NlHostTable()
    {
        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(3));
        columns.addElement(new Long(4));
        columns.addElement(new Long(5));
        columns.addElement(new Long(6));
        columns.addElement(new Long(7));
        columns.addElement(new Long(8));
    }

    public NlHostTable(boolean shared)
    {
        super(shared);

        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(3));
        columns.addElement(new Long(4));
        columns.addElement(new Long(5));
        columns.addElement(new Long(6));
        columns.addElement(new Long(7));
        columns.addElement(new Long(8));
    }

    public AgentXVarBind getVarBind(AgentXEntry entry, long column)
    {
        AgentXOID oid = new AgentXOID(getOID(), column, entry.getInstance());

        switch ((int)column) {
        case 3: // nlHostInPkts
        {
            long value = ((NlHostEntry)entry).get_nlHostInPkts();
            return new AgentXVarBind(oid, AgentXVarBind.GAUGE32, value);
        }
        case 4: // nlHostOutPkts
        {
            long value = ((NlHostEntry)entry).get_nlHostOutPkts();
            return new AgentXVarBind(oid, AgentXVarBind.GAUGE32, value);
        }
        case 5: // nlHostInOctets
        {
            long value = ((NlHostEntry)entry).get_nlHostInOctets();
            return new AgentXVarBind(oid, AgentXVarBind.GAUGE32, value);
        }
        case 6: // nlHostOutOctets
        {
            long value = ((NlHostEntry)entry).get_nlHostOutOctets();
            return new AgentXVarBind(oid, AgentXVarBind.GAUGE32, value);
        }
        case 7: // nlHostOutMacNonUnicastPkts
        {
            long value = ((NlHostEntry)entry).get_nlHostOutMacNonUnicastPkts();
            return new AgentXVarBind(oid, AgentXVarBind.GAUGE32, value);
        }
        case 8: // nlHostCreateTime
        {
            long value = ((NlHostEntry)entry).get_nlHostCreateTime();
            return new AgentXVarBind(oid, AgentXVarBind.TIMETICKS, value);
        }
        }

        return null;
    }

    public int setEntry(AgentXSetPhase phase,
                        AgentXEntry entry,
                        long column,
                        AgentXVarBind vb)
    {

        switch ((int)column) {
        }

        return AgentXResponsePDU.NOT_WRITABLE;
    }

}

