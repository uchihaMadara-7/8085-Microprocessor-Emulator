
void debugging_display()
{
    cout<<endl<<"              ----------------------------------------------------------"<<endl;
    cout<<"              |                    (DEBUGGER OPTIONS):                 |"<<endl;
    cout<<"              |                                                        |"<<endl;
    cout<<"              |  break or b   ------   run or r    ------   step or s  |"<<endl;
    cout<<"              |  print or p   ------   quit or q   ------   help       |"<<endl;
    cout<<"              ----------------------------------------------------------"<<endl<<endl;
}

bool is_number(string number)
{
    for(int i=0;i<number.size();i++)
        if(!isdigit(number[i]))
            return false;
    return true;
}

void debugger(map<string,int> mnemonics,bool with_file,char * file_name)
{
    string s;
    cout<<"               --------------------------------------------"<<endl;
    cout<<"               |  *----- You are in debugger mode -----*  |"<<endl;
    cout<<"               --------------------------------------------"<<endl<<endl;

    if(with_file)
    {
        file_program(mnemonics,file_name);
    }
    else
    {
        processor_8085(mnemonics);
    }

    debugging_display();
    cout<<"              --> ";
    getline(cin,s);
    while(s!="q" && s!="quit")
    {
        if(s=="help")
        {
            cout<<endl<<"              -------------------------------------------------------------------------------------------------"<<endl;
            cout<<"              |  break or b 'line no' :  Set break point given line number                                    |"<<endl;             
            cout<<"              |              run or r :  Run the program until its end or break point is encountered          |"<<endl;
            cout<<"              |             step or s :  It will run one instruction at a time                                |"<<endl;
            cout<<"              |            print or p :  Prints the value of memory location or register                      |"<<endl;
            cout<<"              |                          e.g. p A(prints value in register A) & p 2000(prints value of 2000)  |"<<endl;
            cout<<"              |             quti or q :  quits the debugger                                                   |"<<endl;
            cout<<"              |                  help :  It will show the commands of debugger                                |"<<endl;
            cout<<"              -------------------------------------------------------------------------------------------------"<<endl;
        }

        else if(s.size()>6 && s.substr(0,5)=="break" && is_number(s.substr(6,s.size())))
        {
                int break_point=stoi(s.substr(6,s.size()));
                execution(break_point);
                display();
        }

        else if(s.size()>2 && s.substr(0,1)=="b" && is_number(s.substr(2,s.size())))
        {
                int break_point=stoi(s.substr(2,s.size()));
                execution(break_point);
                display();
        }

        else if(s=="r" || s=="run")
        {
            execution(INT_MAX);
            display();
        }

        else if(s=="s" || s=="step")
        {
            step_execution();
        }

        else if(s.size()==3 && s.substr(0,1)=="p" && (s.substr(2,1)=="A" || s.substr(2,1)=="B" || s.substr(2,1)=="C" || s.substr(2,1)=="D" || 
                   s.substr(2,1)=="E" || s.substr(2,1)=="H" || s.substr(2,1)=="L"))
        {
            string reg=s.substr(2,1);
            cout<<endl<<"               Register "<<s.substr(2,1)<<" : "<< D2H(R[reg[0]])<<endl<<endl;
        }

        else if(s.size()==7 && s.substr(0,5)=="print" && (s.substr(6,1)=="A" || s.substr(6,1)=="B" || s.substr(6,1)=="C" || s.substr(6,1)=="D" || 
                   s.substr(6,1)=="E" || s.substr(6,1)=="H" || s.substr(6,1)=="L"))
        {
            string reg=s.substr(6,1);
            cout<<endl<<"               Register "<<reg[0]<<" : "<< D2H(R[reg[0]])<<endl<<endl;
        }

        else if(s.size()==6 && s.substr(0,1)=="p")
        {
            char *print_str=new char[string(s.substr(2,4)).size()];
            strcpy(print_str,string(s.substr(2,4)).c_str());
            if(data(print_str,4))
            {
                if(memory.find(H2D(s.substr(2,4)))==memory.end())
                    memory[H2D(s.substr(2,4))]="0";

                cout<<endl<<"               Memory Location "<<s.substr(2,4)<<" : "<<D2H(H2D(memory[H2D(s.substr(2,4))]))<<endl<<endl;   
            }
            else 
                cout<<", try the help command"<<endl;
        }

        else if(s.size()==10 && s.substr(0,5)=="print")
        {
            char *print_str=new char[string(s.substr(6,4)).size()];
            strcpy(print_str,string(s.substr(6,4)).c_str());
            if(data(print_str,4))
            {
                if(memory.find(H2D(s.substr(6,4)))==memory.end())
                    memory[H2D(s.substr(6,4))]="0";

                cout<<endl<<"               Memory Location "<<s.substr(6,4)<<" : "<<D2H(H2D(memory[H2D(s.substr(6,4))]))<<endl<<endl;   
            }
            else 
                cout<<", try the help command"<<endl;
        }

        else
        {
            cout<<endl<<"               ----Wrong debugger command, try help----"<<endl<<endl;
        }

        cout<<"              --> ";
        getline(cin,s);
    }
}
