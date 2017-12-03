#include<iostream>
#include<cmath>
using namespace std;

int H2D_Symbol(char x)
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

int H2D(string hex)
{
    int decimal=0;
    for(int i=0;hex[i];i++)
    {
        decimal+=(H2D_Symbol(hex[i])*pow(16,hex.size()-i-1));
    }
    return decimal;
}


