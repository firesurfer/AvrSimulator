/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
#include "Commands/ASR.h"
#include "Commands/LSR.h"
#include "Commands/NEG.h"
#include "Commands/OR.h"
#include "Commands/ORI.h"
#include "Commands/ROR.h"
#include "Commands/SBC.h"
#include "Commands/SBCI.h"
#include "Commands/SBIC.h"
#include "Commands/SBIS.h"
#include "Commands/SBRC.h"
#include "Commands/SBRS.h"
#include "Commands/CPSE.h"
#include "Commands/SBI.h"
#include "Commands/SBIW.h"
#include "Commands/SUB.h"
#include "Commands/SUBI.h"
#include "Commands/IN.h"
#include "Commands/OUT.h"
#include "Commands/LDI.h"
#include "Commands/CALL.h"
#include "Commands/RET.h"
#include "Commands/RETI.h"
#include "Commands/POP.h"
#include "Commands/PUSH.h"
#include "Commands/RCALL.h"
#include "Commands/SPM.h"
#include "Commands/LPM.h"
#include "Commands/LPM_R0.h"
#include "Commands/SLEEP.h"
#include "Commands/WDR.h"
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

#include "Commands/LAC.h"
#include "Commands/LAS.h"
#include "Commands/LAT.h"
#include "Commands/XCH.h"

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
    processor->registerCommand(new RJMP(mapper));
    processor->registerCommand(new NOP(mapper));
    processor->registerCommand(new JMP(mapper));
    processor->registerCommand(new LDS_MEM(mapper));
    processor->registerCommand(new ADC(mapper));
    processor->registerCommand(new ADD(mapper));
    processor->registerCommand(new ADIW(mapper));
    processor->registerCommand(new AND(mapper));
    processor->registerCommand(new ANDI(mapper));
    processor->registerCommand(new BCLR(mapper));
    processor->registerCommand(new BLD(mapper));
    processor->registerCommand(new BRBC(mapper));
    processor->registerCommand(new BRBS(mapper));
    processor->registerCommand(new BSET(mapper));
    processor->registerCommand(new BST(mapper));
    processor->registerCommand(new CBI(mapper));
    processor->registerCommand(new COM(mapper));
    processor->registerCommand(new CP(mapper));
    processor->registerCommand(new CPC(mapper));
    processor->registerCommand(new CPI(mapper));
    processor->registerCommand(new DEC(mapper));
    processor->registerCommand(new EOR(mapper));
    processor->registerCommand(new INC(mapper));
    processor->registerCommand(new LSR(mapper));
    processor->registerCommand(new ASR(mapper));
    processor->registerCommand(new NEG(mapper));
    processor->registerCommand(new OR(mapper));
    processor->registerCommand(new ORI(mapper));
    processor->registerCommand(new ROR(mapper));
    processor->registerCommand(new SBC(mapper));
    processor->registerCommand(new SBCI(mapper));
    processor->registerCommand(new SBIC(mapper));
    processor->registerCommand(new SBIS(mapper));
    processor->registerCommand(new SBRC(mapper));
    processor->registerCommand(new SBRS(mapper));
    processor->registerCommand(new CPSE(mapper));
    processor->registerCommand(new SBI(mapper));
    processor->registerCommand(new SBIW(mapper));
    processor->registerCommand(new SUB(mapper));
    processor->registerCommand(new SUBI(mapper));
    processor->registerCommand(new OUT(mapper));
    processor->registerCommand(new IN(mapper));
    processor->registerCommand(new LDI(mapper));
    processor->registerCommand(new CALL(mapper));
    processor->registerCommand(new RET(mapper));
    processor->registerCommand(new RETI(mapper));
    processor->registerCommand(new POP(mapper));
    processor->registerCommand(new PUSH(mapper));
    processor->registerCommand(new RCALL(mapper));
    processor->registerCommand(new SPM(mapper));
    processor->registerCommand(new LPM(mapper));
    processor->registerCommand(new LPM_R0(mapper));
    processor->registerCommand(new SLEEP(mapper));
    processor->registerCommand(new WDR(mapper));
    processor->registerCommand(new BREAK(mapper));

    processor->registerCommand(new ST_dec_Y(mapper));
    processor->registerCommand(new ST_dec_Z(mapper));
    processor->registerCommand(new ST_X(mapper));
    processor->registerCommand(new ST_Y(mapper));
    processor->registerCommand(new ST_Z(mapper));
    processor->registerCommand(new ST_Y_inc(mapper));
    processor->registerCommand(new ST_Z_inc(mapper));
    processor->registerCommand(new STD_Y(mapper));
    processor->registerCommand(new STD_Z(mapper));
    processor->registerCommand(new STS(mapper));

    processor->registerCommand(new LD_X(mapper));
    processor->registerCommand(new LD_Y(mapper));
    processor->registerCommand(new LD_Z(mapper));
    processor->registerCommand(new LDD_Y(mapper));
    processor->registerCommand(new LDD_Z(mapper));
    processor->registerCommand(new LD_Y_inc(mapper));
    processor->registerCommand(new LD_Z_inc(mapper));
    processor->registerCommand(new LD_dec_Y(mapper));
    processor->registerCommand(new LD_dec_Z(mapper));

    processor->registerCommand(new LAC(mapper));
    processor->registerCommand(new LAS(mapper));
    processor->registerCommand(new LAT(mapper));
    processor->registerCommand(new XCH(mapper));

    processor->registerCommand(new MUL(mapper));
    processor->registerCommand(new MULS(mapper));
    processor->registerCommand(new MULSU(mapper));
    processor->registerCommand(new FMUL(mapper));
    processor->registerCommand(new FMULS(mapper));
    processor->registerCommand(new FMULSU(mapper));

    processor->registerCommand(new MOV(mapper));
    processor->registerCommand(new MOVW(mapper));
    processor->registerCommand(new SWAP(mapper));

}
