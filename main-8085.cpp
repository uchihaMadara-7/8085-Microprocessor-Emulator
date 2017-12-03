#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<ctype.h>
#include<string>
#include<fstream>
#include<climits>

using namespace std;

int PC;
map<char,int> R={{'A',01},{'B',02},{'C',03},{'D',04},
		 {'E',05},{'H',06},{'L',07},{'M',0607}};
map<int,string> memory;
map<string,int> label;
map<int,string> str;
bool F[8]={0};

#include"d2h.h"
#include"h2d.h"
#include"parity.h"
#include"mnemonic.h"
#include"operand.h"
#include"ADD.h"
#include"ADI.h"
#include"MOV.h"
#include"MVI.h"
#include"LXI.h"
#include"XCHG.h"
#include"SUB.h"
#include"SUI.h"
#include"INR.h"
#include"DCR.h"
#include"DAD.h"
#include"CMA.h"
#include"CMP.h"
#include"LDA.h"
#include"STA.h"
#include"LHLD.h"
#include"SHLD.h"
#include"STAX.h"
#include"LDAX.h"
#include"INX.h"
#include"DCX.h"
#include"JMP.h"
#include"JNZ.h"
#include"JZ.h"
#include"JC.h"
#include"JNC.h"
#include"SET.h"
#include"command-implementation.h"
#include"display.h"
#include"execution.h"
#include"pre-processor.h"
#include"file_program.h"
#include"debugger.h"


int main(int argc,char *argv[])
{
	map<string,int> mnemonics;
    mnemonics_map(mnemonics);

    if(argc==1)
    {
        processor_8085(mnemonics);
        execution(INT_MAX);
        display();
    }
    else if(argc==2)
    {
        if(!strcmp(argv[1],"--debugger"))
        {
            debugger(mnemonics,false,argv[1]);
        }
        else
        {
            file_program(mnemonics,argv[1]);
            execution(INT_MAX);
            display();
        }
    }
    else if(argc==3)
    {
        if(!strcmp(argv[1],"--debugger"))
        {
            debugger(mnemonics,true,argv[2]);
        }
    }

   return 0;
}
