void file_program(map<string,int> mnemonics,char *file_name)
{
    vector<string> temp_str;
    string temp;
    ifstream file;
    file.open(file_name);
    if(!file.is_open())
    {
        cout<<endl<<"               No such File Found. Terminating..."<<endl<<endl;
        exit(0);
    }
    else
    {
        int i=0;
        while(!file.eof())
        {
            getline(file,temp);
            temp_str.push_back(temp);
        }
        file.close();
        processor_8085(mnemonics,temp_str);
    }    
}
