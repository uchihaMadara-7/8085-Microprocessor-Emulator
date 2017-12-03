#include<iostream>
#include<stdlib.h>
#include<strings.h>
#include<fstream>
#include<cmath>
#include<climits>
#include<cstring>

using namespace std;

int Hex_to_Decimal_Symbol(char x)
{
    switch(x)
    {
        case 'A':    return 10;
            break;
        case 'B':    return 11;
            break;
        case 'C':    return 12;
            break;
        case 'D':    return 13;
            break;
        case 'E':    return 14;
            break;
        case 'F':    return 15;
            break;
        default:    return x-'0';
    }
}


int Hex_to_Decimal(string hex)
{
    int decimal=0;
    for(int i=0;hex[i];i++)
    {
        decimal+=(Hex_to_Decimal_Symbol(hex[i])*pow(16,hex.size()-i-1));
    }
    return decimal;
}


int main(int argc,char *argv[])
{
    string str[20];
    int b=INT_MAX;
    if(argc==1)
    {
        int i=0;
                getline(cin,str[i]);
                while(str[i]!="HLT")
                {
                    getline(cin,str[++i]);
                }
    }
    else if(argc>=2)
    {
        bool flag=true;
        if(!strcmp(argv[1],"--debugger"))
        {
            string s;
            cout<<"You are in debugger Mode"<<endl;
            cout<<"-> ";
            getline(cin,s);
            while(s!="q" && s!="quit")
            {
                string temp;
                if(s.substr(0,5)=="break")
                {
                    temp=s.substr(6,s.size());
                    b=Hex_to_Decimal(temp);
                }
                else if(s=="run")
                {
                    b=INT_MAX;
                }
                if(flag){
                    ifstream file;
                    file.open(argv[2]);
                    if(!file.is_open())
                    {
                        cout<<"No such File Found";
                        exit(0);
                    }
                    else
                    {
                        int i=0;
                        while(!file.eof())
                            getline(file,str[i++]);
                    }
                    file.close();
                    flag=false;
                }
                cout<<endl<<endl;
                for(int i=0;str[i]!="HLT" && i<b;i++)
                    cout<<str[i]<<endl;
                cout<<endl<<endl;
                cout<<"-> ";
                getline(cin,s);
            }
            if(s=="quit" || s=="q")
                exit(0);
        }
            }

    return 0;
}


