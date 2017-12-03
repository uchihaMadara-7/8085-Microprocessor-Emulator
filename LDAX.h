void LDAX(char *op1)
{
	int mem;
	if(op1[0]=='B')
	{
		mem=H2D(D2H(R['B'])+D2H(R['C']));
	}
	else if(op1[0]=='D')
	{
		mem=H2D(D2H(R['D'])+D2H(R['E']));
	}

	if(memory.find(mem)!=memory.end())
	{
		R['A']=H2D(memory[mem]);
	}
	else
	{
		memory[mem]="0";
		R['A']=H2D(memory[mem]);
	}

}
