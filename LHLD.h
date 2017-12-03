void LHLD(char *op1)
{
	int mem=H2D(string(op1));
	if(memory.find(mem)!=memory.end())
	{
		R['L']=H2D(memory[mem]);
	}
	else
	{
		memory[mem]="0";
		R['L']=H2D(memory[mem]);
	}

	mem++;

	if(memory.find(mem)!=memory.end())
	{
		R['H']=H2D(memory[mem]);
	}
	else
	{
		memory[mem]="0";
		R['H']=H2D(memory[mem]);
	}
}
