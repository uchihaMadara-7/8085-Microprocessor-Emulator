void CMP(char *op1)
{
	if(R[op1[0]]>R['A'])
		{
			F[0]=1;
			F[7]=1;
			F[1]=0;
		}
		else if(R[op1[0]]<R['A'])
			F[7]=F[1]=0;
		else
			F[1]=1;
}
