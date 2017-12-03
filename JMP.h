map<int,string>::iterator JMP(char *op1,map<int,string>::iterator i)
{
	string lab(op1,strlen(op1));
	if(label.find(lab)!=label.end())
	{
		int mem=label[lab];
		return str.find(mem);
	}
	else
	{
		cout<< "No such label found"<<endl;
		exit(0);
	}
}
