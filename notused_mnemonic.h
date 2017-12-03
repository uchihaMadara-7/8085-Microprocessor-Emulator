#include<iostream>
#include<map>
using namespace std;

void mnemonics_map(map<string,int> &mnemonics)
{
   // map<string,int> mnemonics;

    mnemonics["MOV A,A"]=1;
    mnemonics["MOV A,B"]=1;
    mnemonics["MOV A,C"]=1;
    mnemonics["MOV A,D"]=1;
    mnemonics["MOV A,E"]=1;
    mnemonics["MOV A,H"]=1;
    mnemonics["MOV A,L"]=1;
    mnemonics["MOV A,M"]=1;

    opc[73].mnemonic="LXI H,DATA"; opc[73].bytes=3;

    opc[74].mnemonic="LXI SP,DATA"; opc[74].bytes=3;

    opc[75].mnemonic="LDA DATA";    opc[75].bytes=3;

    opc[76].mnemonic="STA DATA";     opc[76].bytes=3;

    opc[77].mnemonic="LHLD DATA";    opc[77].bytes=3;

    opc[78].mnemonic="SHLD DATA";   opc[78].bytes=3;

    opc[79].mnemonic="STAX B"; 	opc[79].bytes=1;

    opc[80].mnemonic="STAX D"; opc[80].bytes=1;

    opc[81].mnemonic="LDAX B"; opc[81].bytes=1;

    opc[82].mnemonic="LDAX D"; opc[82].bytes=1;

    opc[83].mnemonic="XCHG"; opc[83].bytes=1;

    opc[84].mnemonic="SET ADDR,DATA"; opc[84].bytes=4;

    opc[85].mnemonic="ADD A"; opc[85].bytes=1;

    opc[86].mnemonic="ADD B"; opc[86].bytes=1;

    opc[87].mnemonic="ADD C"; opc[87].bytes=1;

    opc[88].mnemonic="ADD D"; opc[88].bytes=1;

    opc[89].mnemonic="ADD E"; opc[89].bytes=1;

    opc[90].mnemonic="ADD H"; opc[90].bytes=1;

    opc[91].mnemonic="ADD L"; opc[91].bytes=1;

    opc[92].mnemonic="ADD M"; opc[92].bytes=1;

    opc[93].mnemonic="ADI DATA"; opc[93].bytes=2;

    opc[94].mnemonic="SUB A";  opc[94].bytes=1;

    opc[95].mnemonic="SUB B";  opc[95].bytes=1;

    opc[96].mnemonic="SUB C";   opc[96].bytes=1;

    opc[97].mnemonic="SUB D";  opc[97].bytes=1;

    opc[98].mnemonic="SUB E";  opc[98].bytes=1;

    opc[99].mnemonic="SUB H";  opc[99].bytes=1;

    opc[100].mnemonic="SUB L"; opc[100].bytes=1;

    opc[101].mnemonic="SUB M"; opc[101].bytes=1;

    opc[102].mnemonic="INR A"; opc[102].bytes=1;

    opc[103].mnemonic="INR B"; opc[103].bytes=1;

    opc[104].mnemonic="INR C";; opc[104].bytes=1;

    opc[105].mnemonic="INR D"; opc[105].bytes=1;

    opc[106].mnemonic="INR E"; opc[106].bytes=1;

    opc[107].mnemonic="INR H"; opc[107].bytes=1;

    opc[108].mnemonic="INR L"; opc[108].bytes=1;

    opc[109].mnemonic="INR M"; opc[109].bytes=1;

    opc[110].mnemonic="DCR A"; opc[110].bytes=1;

    opc[111].mnemonic="DCR B"; opc[111].bytes=1;

    opc[112].mnemonic="DCR C";; opc[112].bytes=1;

    opc[113].mnemonic="DCR D"; opc[113].bytes=1;

    opc[114].mnemonic="DCR E"; opc[114].bytes=1;

    opc[115].mnemonic="DCR H"; opc[115].bytes=1;

    opc[116].mnemonic="DCR L"; opc[116].bytes=1;

    opc[117].mnemonic="DCR M"; opc[117].bytes=1;

    opc[118].mnemonic="INX B"; opc[118].bytes=1;

    opc[119].mnemonic="INX D"; opc[119].bytes=1;

    opc[120].mnemonic="INX H"; opc[120].bytes=1;

    opc[121].mnemonic="INX SP"; opc[121].bytes=1;

    opc[122].mnemonic="DCX B"; opc[122].bytes=1;

    opc[123].mnemonic="DCX D"; opc[123].bytes=1;

    opc[124].mnemonic="DCX H"; opc[124].bytes=1;

    opc[125].mnemonic="DCX SP"; opc[125].bytes=1;

    opc[126].mnemonic="DAD B"; opc[126].bytes=1;

    opc[127].mnemonic="DAD D"; opc[127].bytes=1;

    opc[128].mnemonic="DAD H"; opc[128].bytes=1;

    opc[129].mnemonic="DAD SP"; opc[129].bytes=1;

    opc[130].mnemonic="CMA";   opc[130].bytes=1;

    opc[131].mnemonic="CMP A"; opc[131].bytes=1;

    opc[132].mnemonic="CMP B"; opc[132].bytes=1;

    opc[133].mnemonic="CMP C"; opc[133].bytes=1;

    opc[134].mnemonic="CMP D"; opc[134].bytes=1;

    opc[135].mnemonic="CMP E"; opc[135].bytes=1;

    opc[136].mnemonic="CMP H"; opc[136].bytes=1;

    opc[137].mnemonic="CMP L"; opc[137].bytes=1;

    opc[138].mnemonic="CMP M"; opc[138].bytes=1;

    opc[139].mnemonic="SUI DATA"; opc[139].bytes=2;

    opc[140].mnemonic="JNZ LABEL"; opc[140].bytes=3;

    opc[141].mnemonic="JZ LABEL"; opc[141].bytes=3;

    opc[142].mnemonic="JNC LABEL"; opc[142].bytes=3;

    opc[143].mnemonic="JC LABEL"; opc[143].bytes=3;

    opc[144].mnemonic="JMP LABEL"; opc[144].bytes=3;
*/
}
