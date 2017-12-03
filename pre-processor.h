void processor_8085(map<string,int> mnemonics,vector<string> temp_str)
{
	int start,i=0;
	string temp,data1="Q",data2="F";
	temp=temp_str[0];
	char *temp1=new char[temp.size()];
	strcpy(temp1,temp.c_str());
	if(!data(temp1,temp.size()) || temp.size()>4)
	{
		cout<<"               Invalid Address"<<endl;
		exit(0);
	}
	start=H2D(temp);
	PC=start;
	if(D2H(start).size()==2)
		cout<<"                          00"<<D2H(start)<<" : ";
	else
		cout<<"                          "<<D2H(start)<<" : ";
	temp=temp_str[1];
    cout<<temp<<endl;
	if(mnemonic_validator(temp,mnemonics,label,data1,data2))
	{
		str[start]=temp;
		memory[start]=temp;
	}
	else
	{
		cout<<"               Terminating..."<<endl<<endl;
		exit(0);
	}
    i=2;
	while(temp!="HLT")
	{
		start=PC;
		if(D2H(start).size()==2)
			cout<<"                          00"<<D2H(start)<<" : ";
		else
			cout<<"                          "<<D2H(start)<<" : ";
		temp=temp_str[i];
        cout<<temp<<endl;
		if(mnemonic_validator(temp,mnemonics,label,data1,data2))
		{
			str[start]=temp;
			memory[start]=temp;
            i++;
		}
		else
		{
			cout<<"               Terminating..."<<endl<<endl;
			exit(0);
		}
	}

}

void processor_8085(map<string,int> mnemonics)
{
	int start,i=0;
	string temp,data1="Q",data2="F";
	cout<<"               Enter Starting Address of 8085 Program: ";
	cin>>temp;
	char *temp1=new char[temp.size()];
	strcpy(temp1,temp.c_str());
	if(!data(temp1,temp.size()) || temp.size()>4)
	{
		cout<<"               Invalid Address"<<endl;
		exit(0);
	}
	start=H2D(temp);
	PC=start;
	if(D2H(start).size()==2)
		cout<<"                          00"<<D2H(start)<<" : ";
	else
		cout<<"                          "<<D2H(start)<<" : ";
	cin.ignore();
	getline(cin,temp);
	if(mnemonic_validator(temp,mnemonics,label,data1,data2))
	{
		str[start]=temp;
		memory[start]=temp;
	}
	else
	{
		cout<<"               Terminating..."<<endl<<endl;
		exit(0);
	}
	while(temp!="HLT")
	{
		start=PC;
		if(D2H(start).size()==2)
			cout<<"                          00"<<D2H(start)<<" : ";
		else
			cout<<"                          "<<D2H(start)<<" : ";
		getline(cin,temp);
		if(mnemonic_validator(temp,mnemonics,label,data1,data2))
		{
			str[start]=temp;
			memory[start]=temp;
		}
		else
		{
			cout<<"               Terminating..."<<endl<<endl;
			exit(0);
		}
	}

}