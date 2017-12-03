void LDA(char *op1)
{
	int mem=H2D(string(op1));
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
