#include<iostream>
#include<map>
using namespace std;

void mnemonics_map(map<string,int> &mnemonics)
{
	mnemonics["MOV"]=1;
	mnemonics["MVI"]=2;
	mnemonics["LXI"]=3;
	mnemonics["LDA"]=3;
	mnemonics["STA"]=3;
	mnemonics["LHLD"]=3;
	mnemonics["SHLD"]=3;
	mnemonics["STAX"]=1;
	mnemonics["LDAX"]=1;
	mnemonics["XCHG"]=1;
	mnemonics["SET"]=4;
	mnemonics["ADD"]=1;
	mnemonics["ADI"]=2;
	mnemonics["SUB"]=1;
	mnemonics["INR"]=1;
	mnemonics["DCR"]=1;
	mnemonics["INX"]=1;
	mnemonics["DCX"]=1;
	mnemonics["DAD"]=1;
	mnemonics["CMA"]=1;
	mnemonics["CMP"]=1;
	mnemonics["SUI"]=2;
	mnemonics["JNZ"]=3;
	mnemonics["JZ"]=3;
	mnemonics["JNC"]=3;
	mnemonics["JC"]=3;
	mnemonics["JMP"]=3;
	mnemonics["HLT"]=1;
}
