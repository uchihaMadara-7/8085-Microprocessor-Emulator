void LXI(char *op1,char *op2)
{

	string op(op2,strlen(op2));

	string higher;
	higher.push_back(op[0]);
	higher.push_back(op[1]);

	string lower;
	lower.push_back(op[2]);
	lower.push_back(op[3]);

	if(op1[0]=='B')
	{
		R['B']=H2D(higher);
		R['C']=H2D(lower);
	}
	else if(op1[0]=='D')
        {
                R['D']=H2D(higher);
                R['E']=H2D(lower);
        }
	else if(op1[0]=='H')
        {
                R['H']=H2D(higher);
                R['L']=H2D(lower);
        }
}
