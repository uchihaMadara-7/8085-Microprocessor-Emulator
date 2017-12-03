void DCR(char *op1)
{
	if(R[op1[0]]%10<1)
                        F[3]=1;
                else
                        F[3]=0;
		if(R[op1[0]]==0)
			R[op1[0]]=255;
		else
                	R[op1[0]]--;
                if(R[op1[0]]==0)
                        F[1]=1;
                else
                        F[1]=0;
                if(R[op1[0]]>=128 && R[op1[0]]<=255)
                        F[0]=0;
                else
                        F[0]=1;
                if(parity(R[op1[0]]))
                        F[5]=0;
                else
                        F[5]=1;
}
