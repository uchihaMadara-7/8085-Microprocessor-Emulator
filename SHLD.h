void SHLD(char *op1)
{
	int mem=H2D(string(op1));
        memory[mem]=D2H(R['L']);
	mem++;
	memory[mem]=D2H(R['H']);
}
