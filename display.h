void display()
{
    cout<<endl<<"               ----------------------------------------"<<endl;

    cout<<"               |   B : "<<D2H(R['B'])<<"   |   C : "<<D2H(R['C'])<<"   |   D : "<<D2H(R['D'])<<"   |"<<endl;

    cout<<"               ----------------------------------------"<<endl;

    cout<<"               |   E : "<<D2H(R['E'])<<"   |   H : "<<D2H(R['H'])<<"   |   L : "<<D2H(R['L'])<<"   |"<<endl;

    cout<<"               ----------------------------------------"<<endl<<endl;

    cout<<"                Accumulator: "<<D2H(R['A'])<<endl<<endl;

    cout<<"               ------------------------------------------------------------------"<<endl;

    cout<<"               |  S \t|  Z \t|  X \t|  AC\t|  X \t|  P \t|  X \t|  C \t|"<<endl;

    cout<<"               |  ";
    for(int i=0;i<8;i++)
    {

        cout<<F[i]<<" \t|  ";

    }

    cout<<endl<<"               ------------------------------------------------------------------"<<endl;

    cout<<endl<<endl;

    for(map<int,string>::iterator i=str.begin();i!=str.end();++i)
    {
        cout<<"                "<< D2H(i->first) << " : " << i->second <<endl;
    }

    cout<<"              --------------------------------";
	cout<<"\n              |     Memory Location Used   "<<endl;
    cout<<"              |"<<endl;
	for(map<int,string>::iterator i=memory.begin();i!=memory.end();++i)
	{
		cout<<"              |  "<< D2H(i->first) << " : " << i->second <<endl;
	}
    cout<<"              --------------------------------"<<endl;

	cout<<"\n                Label: "<<endl;

	for(map<string,int>::iterator i=label.begin();i!=label.end();++i)
    {
         cout<<"                "<< i->first << " : " << D2H(i->second) <<endl;
    }

    cout<<endl;

}
