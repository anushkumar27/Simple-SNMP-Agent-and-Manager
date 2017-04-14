/*
 * This Java file has been generated by smidump 0.4.5. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id: NlHostEntry.java 1458 2006-05-29 16:21:11Z strauss $
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table row nlHostEntry defined in RMON2-MIB.

    @version 1
    @author  smidump 0.4.5
    @see     AgentXTable, AgentXEntry
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class NlHostEntry extends AgentXEntry
{

    protected long nlHostTimeMark = 0;
    protected byte[] nlHostAddress = new byte[0];
    protected long nlHostInPkts = 0;
    protected long nlHostOutPkts = 0;
    protected long nlHostInOctets = 0;
    protected long nlHostOutOctets = 0;
    protected long nlHostOutMacNonUnicastPkts = 0;
    protected long nlHostCreateTime = 0;
    // foreign indices
    protected int hlHostControlIndex;
    protected int protocolDirLocalIndex;

    public NlHostEntry(int hlHostControlIndex,
                       long nlHostTimeMark,
                       int protocolDirLocalIndex,
                       byte[] nlHostAddress)
    {
        this.hlHostControlIndex = hlHostControlIndex;
        this.nlHostTimeMark = nlHostTimeMark;
        this.protocolDirLocalIndex = protocolDirLocalIndex;
        this.nlHostAddress = nlHostAddress;

        instance.append(hlHostControlIndex);
        instance.append(nlHostTimeMark);
        instance.append(protocolDirLocalIndex);
        instance.append(nlHostAddress);
    }

    public int get_hlHostControlIndex()
    {
        return hlHostControlIndex;
    }

    public long get_nlHostTimeMark()
    {
        return nlHostTimeMark;
    }

    public int get_protocolDirLocalIndex()
    {
        return protocolDirLocalIndex;
    }

    public byte[] get_nlHostAddress()
    {
        return nlHostAddress;
    }

    public long get_nlHostInPkts()
    {
        return nlHostInPkts;
    }

    public long get_nlHostOutPkts()
    {
        return nlHostOutPkts;
    }

    public long get_nlHostInOctets()
    {
        return nlHostInOctets;
    }

    public long get_nlHostOutOctets()
    {
        return nlHostOutOctets;
    }

    public long get_nlHostOutMacNonUnicastPkts()
    {
        return nlHostOutMacNonUnicastPkts;
    }

    public long get_nlHostCreateTime()
    {
        return nlHostCreateTime;
    }

}

