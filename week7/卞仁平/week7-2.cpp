#include <bits/stdc++.h>
using namespace std;
string read()
{
    string s="";
    string t;
    char x;
    int n;
    while(cin>>x)
    {
        if(x=='[')
        {
            cin>>n;
            t=read();
            while(n--)
            s+=t;
        }
        else
        {
            if(x==']')
            return s;
            else s+=x;
        }
    }
}
int main()
{
    
    cout<<read();
    return 0;
}