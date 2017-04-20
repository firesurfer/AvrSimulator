#include "CommandRegister.h"
#include "Commands/RJMP.h"
#include "Commands/NOP.h"
#include "Commands/JMP.h"
#include "Commands/LDS_MEM.h"
#include "Commands/ADC.h"
#include "Commands/ADD.h"
#include "Commands/ADIW.h"
#include "Commands/AND.h"
#include "Commands/ANDI.h"
#include "Commands/BCLR.h"
#include "Commands/BLD.h"
#include "Commands/BRBC.h"
#include "Commands/BRBS.h"
#include "Commands/BSET.h"
#include "Commands/BST.h"
#include "Commands/CBI.h"
#include "Commands/COM.h"
#include "Commands/CP.h"
#include "Commands/CPC.h"
#include "Commands/CPI.h"
#include "Commands/DEC.h"
#include "Commands/EOR.h"
#include "Commands/INC.h"
#include "Commands/LSR.h"
#include "Commands/NEG.h"
#include "Commands/OR.h"
#include "Commands/ORI.h"
#include "Commands/ROR.h"
#include "Commands/SBC.h"
#include "Commands/SBIC.h"
#include "Commands/SBIS.h"
#include "Commands/SBI.h"
#include "Commands/SBIW.h"
#include "Commands/SUB.h"
#include "Commands/SUBI.h"
#include "Commands/IN.h"
#include "Commands/OUT.h"
#include "Commands/LDI.h"
#include "Commands/CALL.h"
#include "Commands/RET.h"
#include "Commands/POP.h"
#include "Commands/PUSH.h"
#include "Commands/RCALL.h"
#include "Commands/SPM.h"
#include "Commands/LPM.h"
#include "Commands/LPM_R0.h"
#include "Commands/BREAK.h"

#include "Commands/ST_dec_Y.h"
#include "Commands/ST_dec_Z.h"
#include "Commands/ST_X.h"
#include "Commands/ST_Y.h"
#include "Commands/ST_Y_inc.h"
#include "Commands/ST_Z_inc.h"
#include "Commands/ST_Z.h"
#include "Commands/STD_Y.h"
#include "Commands/STD_Z.h"
#include "Commands/STS.h"

#include "Commands/LD_X.h"
#include "Commands/LD_Y.h"
#include "Commands/LD_Z.h"
#include "Commands/LDD_Y.h"
#include "Commands/LDD_Z.h"
#include "Commands/LD_dec_Y.h"
#include "Commands/LD_dec_Z.h"
#include "Commands/LD_Y_inc.h"
#include "Commands/LD_Z_inc.h"

#include "Commands/MUL.h"
#include "Commands/MULS.h"
#include "Commands/MULSU.h"
#include "Commands/FMUL.h"
#include "Commands/FMULS.h"
#include "Commands/FMULSU.h"
#include "Commands/MOV.h"
#include "Commands/MOVW.h"
#include "Commands/SWAP.h"

void CommandRegister::registerCommand(Processor *processor, MemoryMapper *mapper)
{
    processor->RegisterCommand(new RJMP(mapper));
    processor->RegisterCommand(new NOP(mapper));
    processor->RegisterCommand(new JMP(mapper));
    processor->RegisterCommand(new LDS_MEM(mapper));
    processor->RegisterCommand(new ADC(mapper));
    processor->RegisterCommand(new ADD(mapper));
    processor->RegisterCommand(new ADIW(mapper));
    processor->RegisterCommand(new AND(mapper));
    processor->RegisterCommand(new ANDI(mapper));
    processor->RegisterCommand(new BCLR(mapper));
    processor->RegisterCommand(new BLD(mapper));
    processor->RegisterCommand(new BRBC(mapper));
    processor->RegisterCommand(new BRBS(mapper));
    processor->RegisterCommand(new BSET(mapper));
    processor->RegisterCommand(new BST(mapper));
    processor->RegisterCommand(new CBI(mapper));
    processor->RegisterCommand(new COM(mapper));
    processor->RegisterCommand(new CP(mapper));
    processor->RegisterCommand(new CPC(mapper));
    processor->RegisterCommand(new CPI(mapper));
    processor->RegisterCommand(new DEC(mapper));
    processor->RegisterCommand(new EOR(mapper));
    processor->RegisterCommand(new INC(mapper));
    processor->RegisterCommand(new LSR(mapper));
    processor->RegisterCommand(new NEG(mapper));
    processor->RegisterCommand(new OR(mapper));
    processor->RegisterCommand(new ORI(mapper));
    processor->RegisterCommand(new ROR(mapper));
    processor->RegisterCommand(new SBC(mapper));
    processor->RegisterCommand(new SBIC(mapper));
    processor->RegisterCommand(new SBIS(mapper));
    processor->RegisterCommand(new SBI(mapper));
    processor->RegisterCommand(new SBIW(mapper));
    processor->RegisterCommand(new SUB(mapper));
    processor->RegisterCommand(new SUBI(mapper));
    processor->RegisterCommand(new OUT(mapper));
    processor->RegisterCommand(new IN(mapper));
    processor->RegisterCommand(new LDI(mapper));
    processor->RegisterCommand(new CALL(mapper));
    processor->RegisterCommand(new RET(mapper));
    processor->RegisterCommand(new POP(mapper));
    processor->RegisterCommand(new PUSH(mapper));
    processor->RegisterCommand(new RCALL(mapper));
    processor->RegisterCommand(new SPM(mapper));
    processor->RegisterCommand(new LPM(mapper));
    processor->RegisterCommand(new LPM_R0(mapper));
    processor->RegisterCommand(new BREAK(mapper));


    processor->RegisterCommand(new ST_dec_Y(mapper));
    processor->RegisterCommand(new ST_dec_Z(mapper));
    processor->RegisterCommand(new ST_X(mapper));
    processor->RegisterCommand(new ST_Y(mapper));
    processor->RegisterCommand(new ST_Z(mapper));
    processor->RegisterCommand(new ST_Y_inc(mapper));
    processor->RegisterCommand(new ST_Z_inc(mapper));
    processor->RegisterCommand(new STD_Y(mapper));
    processor->RegisterCommand(new STD_Z(mapper));
    processor->RegisterCommand(new STS(mapper));

    processor->RegisterCommand(new LD_X(mapper));
    processor->RegisterCommand(new LD_Y(mapper));
    processor->RegisterCommand(new LD_Z(mapper));
    processor->RegisterCommand(new LDD_Y(mapper));
    processor->RegisterCommand(new LDD_Z(mapper));
    processor->RegisterCommand(new LD_Y_inc(mapper));
    processor->RegisterCommand(new LD_Z_inc(mapper));
    processor->RegisterCommand(new LD_dec_Y(mapper));
    processor->RegisterCommand(new LD_dec_Z(mapper));

    processor->RegisterCommand(new MUL(mapper));
    processor->RegisterCommand(new MULS(mapper));
    processor->RegisterCommand(new MULSU(mapper));
    processor->RegisterCommand(new FMUL(mapper));
    processor->RegisterCommand(new FMULS(mapper));
    processor->RegisterCommand(new FMULSU(mapper));

    processor->RegisterCommand(new MOV(mapper));
    processor->RegisterCommand(new MOVW(mapper));
    processor->RegisterCommand(new SWAP(mapper));

}
