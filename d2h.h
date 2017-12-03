#include<iostream>
#include<algorithm>
using namespace std;

char D2H_Symbol(int x)
{
    switch(x)
    {
        case 10:    return 'A';
            break;
        case 11:    return 'B';
            break;
        case 12:    return 'C';
            break;
        case 13:    return 'D';
            break;
        case 14:    return 'E';
            break;
        case 15:    return 'F';
            break;
        default:    return x+'0';
    }
}

string D2H(int decimal)
{
    string hex;
    while(decimal)
    {
        hex.push_back(D2H_Symbol(decimal%16));
        decimal/=16;
    }
     if(hex.size()==0)
        hex.push_back('0');
    if(hex.size()%2)
        hex.push_back('0');
    reverse(hex.begin(),hex.end());
    return hex;
}
