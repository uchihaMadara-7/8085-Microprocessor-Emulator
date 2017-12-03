void SUB(char *op1)
{
	if(R['A']%10<R[op1[0]]%10)
                        F[3]=1;
                else
                        F[3]=0;
		if(R[op1[0]]>R['A'])
		{
			R['A']+=256;
			F[7]=1;
		}
		else
			F[7]=0;
                R['A']-=R[op1[0]];
                if(R['A']==0)
                        F[1]=1;
                else
                        F[1]=0;
                if(R['A']>=128 && R['A']<=255)
                        F[0]=0;
                else
                        F[0]=1;
                if(parity(R['A']))
                        F[5]=0;
		else
			F[5]=1;
}
