map<int,string>::iterator command(string s,map<int,string>::iterator i)
{
	char *str=new char[s.size()];
	strcpy(str,s.c_str());
	char *ins=strtok(str," ");
	string instruction(ins,strlen(ins));
	char *op1,*op2;
	if(ins!=NULL)
		op1=strtok(NULL,",");
	if(op1!=NULL)
		op2=strtok(NULL,",");
	int mem;
	if( (op1!=NULL && op1[0]=='M') || (op2!=NULL && op2[0]=='M'))
	{
		R['M']=mem=H2D(D2H(R['H'])+D2H(R['L']));

		if(memory.find(mem)!=memory.end())
			R['M']=H2D(memory[R['M']]);
		else
		{
			memory[mem]="0";
			R['M']=H2D(memory[R['M']]);
		}
	}

	if(instruction=="MOV")
	{
		MOV(op1,op2);
	}

	else if(instruction=="MVI")
	{
		MVI(op1,op2);
	}

	else if(instruction=="LXI")
	{
		LXI(op1,op2);
	}

	else if(instruction=="LDA")
	{
		LDA(op1);
	}

	else if(instruction=="STA")
	{
		STA(op1);
	}

	else if(instruction=="LHLD")
	{
		LHLD(op1);
	}

	else if(instruction=="SHLD")
	{
		SHLD(op1);
	}

	else if(instruction=="STAX")
	{
		STAX(op1);
	}

	else if(instruction=="LDAX")
	{
		LDAX(op1);
	}

	else if(instruction=="INX")
	{
		INX(op1);
	}

	else if(instruction=="DCX")
	{
		DCX(op1);
	}

	else if(instruction=="XCHG")
	{
		XCHG();
	}

	else if(instruction=="ADD")
	{
		ADD(op1);
	}

	else if(instruction=="ADI")
	{
		ADI(op1);
	}

	else if(instruction=="SUB")
        {
                SUB(op1);
	}

	 else if(instruction=="SUI")
        {
		SUI(op1);
        }

	else if(instruction=="INR")
        {
                INR(op1);
	}

	else if(instruction=="DCR")
        {
                DCR(op1);
        }

	else if(instruction=="DAD")
	{
		DAD(op1);
	}

	else if(instruction=="CMA")
	{
		CMA();
	}

	else if(instruction=="CMP")
	{
		CMP(op1);
	}

	else if(instruction=="JMP")
	{
		return JMP(op1,i);
	}

	else if(instruction=="JNZ")
	{
		return JNZ(op1,i);
	}

	else if(instruction=="JZ")
	{
		return JZ(op1,i);
	}

	else if(instruction=="JNC")
        {
                return JNC(op1,i);
        }

	else if(instruction=="JC")
        {
                return JC(op1,i);
        }

	else if(instruction=="SET")
	{
		SET(op1,op2);
	}

	if((op1!=NULL && op1[0]=='M') || (op2!=NULL && op2[0]=='M'))
	{
		memory[mem]=D2H(R['M']);
	}

	return ++i;
}
