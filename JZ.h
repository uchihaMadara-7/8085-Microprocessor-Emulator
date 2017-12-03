map<int,string>::iterator JZ(char *op1,map<int,string>::iterator i)
{
        string lab(op1,strlen(op1));
        if(label.find(lab)!=label.end())
        {
                int mem=label[lab];
                if(F[1])
                {
                        return str.find(mem);
                }

                return ++i;
        }
        else
        {
                cout<< "No Label "<< lab << " found"<<endl;
                exit(0);
        }
}


