void INX(char *op1)
{
	char op2;
	if(op1[0]=='B')
	{
		op2='C';
	}
	else if(op1[0]=='D')
	{
		op2='E';
	}
	else if(op1[0]=='H')
	{
		op2='L';
	}

	if(R[op2]==255)
	{
		R[op2]=0;
		if(R[op1[0]]==255)
			R[op1[0]]=0;
		else
			R[op1[0]]++;
	}
	else
		R[op2]++;

}
