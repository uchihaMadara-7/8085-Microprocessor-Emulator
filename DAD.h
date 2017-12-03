void DAD(char *op1)
{
	int data=H2D(D2H(R['H'])+D2H(R['L']));

	int data1;
	if(op1[0]=='B')
	{
		data1=H2D(D2H(R['B'])+D2H(R['C']));
	}
	if(op1[0]=='D')
        {
                data1=H2D(D2H(R['D'])+D2H(R['E']));
        }
	if(op1[0]=='H')
        {
                data1=data;
        }

	data+=data1;
	if(data>65535)
	{
		F[7]=1;
		data--;
		data%65535;
	}
	else
		F[7]=0;
	R['L']=data%100;
	data/=100;
	R['H']=data;
}
