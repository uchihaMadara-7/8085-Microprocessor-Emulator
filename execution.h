void execution(int break_point)
{
    for(map<int,string>::iterator i=str.begin();i!=str.end();)
    {
        if(break_point==0)
        {
            return;
        }
        break_point--;

        i=command(i->second,i);   
    }
}

void step_execution()
{
    char c;
    for(map<int,string>::iterator i=str.begin();i!=str.end();)
    {
        cout<<endl<<"               Instruction: "<< i->second <<endl;
        i=command(i->second,i);
        display();
        cout<<"               Press any button to execute next instruction"<<endl;
        cin.get(c);
    }
}