#include<iostream>
#include<cstring>
using namespace std;

bool Register(char *r)
{
	if(r==NULL)
	{
		cout<<"               No Register Provided"<<endl;
		return false;
	}
	string reg(r,strlen(r));
	if(reg=="A" || reg=="B" || reg=="C" || reg=="D" || reg=="E" || reg=="H" || reg=="L" || reg=="M")
		return true;
	cout<<"               Invalid Registers"<<endl;
	return false;
}

bool data(char *r,int l)
{
	if(r==NULL)
	{
		cout<<"               No data operand provided"<<endl;
		return false;
	}

	string d(r,strlen(r));
	if(d.size()==l)
	{
		for(int i=0;d[i];i++)
		{
			if(!(H2D_Symbol(d[i])>=0 && H2D_Symbol(d[i])<=15))
			{
				cout<<"               Not a Hexadecimal Number"<<endl;
				return false;
			}
		}
		return true;
	}
	cout<<"               Length of Operand is wrong"<<endl;
	return false;
}

bool label_validator(char *op1)
{
	string lab(op1,strlen(op1));
        if(label.find(lab)!=label.end())
        {
                return true;
        }
	cout<<"               No label named "<<lab<<" found"<<endl;
	return false;
}

bool operand_validator(string s,map<string,int> mnemonics,string &data1,string &data2)
{

	char *str=new char[s.size()];
        strcpy(str,s.c_str());
        char *instruction=strtok(str," ");
	string ins(instruction,strlen(instruction));

	if(mnemonics.find(ins)==mnemonics.end())
	{
		cout<<"               No such instruction"<<endl;
		return false;
	}

	char *operand1=NULL,*operand2=NULL;
	PC+=mnemonics[ins];
	if(instruction!=NULL)
	{
		operand1=strtok(NULL,",");
	}
	if(operand1!=NULL)
	{
		operand2=strtok(NULL,",");
	}

	if(operand1!=NULL)
	{
		string o1(operand1,strlen(operand1));
		data1=o1;
	}
	if(operand2!=NULL)
	{
		string o2(operand2,strlen(operand2));
		data2=o2;
	}

	if(ins=="MOV" && Register(operand1) && Register(operand2))
			return true;
	if(ins=="MVI" && Register(operand1) && data(operand2,2))
			return true;
	if(ins=="LXI" && data(operand2,4))
		if(data1=="B" || data1=="D" || data1=="H" || data1=="SP")
				return true;
	if(ins=="LDA" && data(operand1,4) && operand2==NULL)
		return true;
	if(ins=="STA" && data(operand1,4) && operand2==NULL)
		return true;
	if(ins=="LHLD" && data(operand1,4) && operand2==NULL)
		return true;
	if(ins=="SHLD" && data(operand1,4) && operand2==NULL)
		return true;
	if(ins=="STAX" && operand2==NULL)
		if(data1=="B" || data1=="D")
			return true;
	if(ins=="LDAX" && operand2==NULL)
		if(data1=="B" || data1=="D")
			return true;
	if(ins=="XCHG" && ins.size()==s.size())
		return true;
	if(ins=="SET" && data(operand1,4) && data(operand2,2))
		return true;
	if(ins=="ADD" && Register(operand1) && operand2==NULL)
		return true;
	if(ins=="ADI" && data(operand1,2) && operand2==NULL)
		return true;
	if(ins=="SUB" && Register(operand1) && operand2==NULL)
		return true;
	if(ins=="SUI" && data(operand1,2) && operand2==NULL)
		return true;
	if(ins=="INR" && Register(operand1) && operand2==NULL)
		return true;
	if(ins=="DCR" && Register(operand1) && operand2==NULL)
		return true;
	if(ins=="INX" && operand2==NULL)
		if(data1=="B" || data1=="D" || data1=="H" || data1=="SP")
			return true;
	if(ins=="DCX" && operand2==NULL)
		if(data1=="B" || data1=="D" || data1=="H" || data1=="SP")
			return true;
	if(ins=="DAD" && operand2==NULL)
		if(data1=="B" || data1=="D" || data1=="H" || data1=="SP")
		return true;
	if(ins=="CMA" && ins.size()==s.size())
		return true;
	if(ins=="CMP" && Register(operand1) && operand2==NULL)
		return true;
	if(ins=="JNZ" && operand1!=NULL && label_validator(operand1) && operand2==NULL)
 		return true;
	if(ins=="JZ" && operand1!=NULL && label_validator(operand1) && operand2==NULL)
   		return true;
	if(ins=="JNC" && operand1!=NULL && label_validator(operand1) && operand2==NULL)
		return true;
	if(ins=="JC" && operand1!=NULL && label_validator(operand1) && operand2==NULL)
		return true;
	if(ins=="JMP" && operand1!=NULL && label_validator(operand1) && operand2==NULL)
		return true;
	if(ins=="HLT" && ins.size()==s.size())
		return true;
	cout<<"               80805 doesn't not support the statement"<<endl;
	return false;
}

bool mnemonic_validator(string &s,map<string,int> mnemonics,map<string,int> &label,string &data1,string &data2)
{
	if(s=="")
		return true;

	char *str=new char[s.size()];
	strcpy(str,s.c_str());
	char *instruction=strtok(str," ");
	string ins(instruction,strlen(instruction));

	if(mnemonics.find(instruction)!=mnemonics.end())
	{
		return operand_validator(s,mnemonics,data1,data2);
	}

	if(!isalpha(ins[0]))
	{
		cout<<"               Labels cannot start with number"<<endl;
		return false;
	}

	if(label.find(ins)!=label.end())
	{
		cout<<"               Duplicate labels"<<endl;
		return false;
	}
	else
		label[ins]=PC+=mnemonics[ins];

    if(instruction!=NULL)
	{
			instruction=strtok(NULL,"");
	}
	else
	{
		cout<<"               Invalid Instruction"<<endl;
		return false;
	}

	if(instruction!=NULL)
		s=string(instruction);

	if(instruction!=NULL)
		return operand_validator(string(instruction),mnemonics,data1,data2);

	cout<<"               Something went wrong, may be check your command"<<endl;
	return false;
}
