#include <iostream>
using namespace std;
string s;
int i;
bool search1(int l)
{
    while(i<l)
    {
        int n=0;
        if(s[i]=='(')
            n++;
        if(s[i]==')')
        {
            if(n==0)
                return 1;
            else
                n--;
        }
        i++;
    }
    return 0;
}
bool search2(int l)
{
    while(i<l)
    {
        int n=0;
        if(s[i]=='[')
            n++;
        if(s[i]==']')
        {
            if(n==0)
                return 1;
            else
                n--;
        }
        i++;
    }
    return 0;
}
bool search3(int l)
{
    while(i<l)
    {
        int n=0;
        if(s[i]=='{')
            n++;
        if(s[i]=='}')
        {
            if(n==0)
                return 1;
            else
                n--;
        }
        i++;
    }
    return 0;
}

int main()
{
    cin>>s;
    int l=s.length();
    int flag=1;
    while(i<l)
    {
        if(s[i]=='(')
        {
            if(!search1(l))
            {
                flag=0;
                break;
            }
            
        }
        if(s[i]=='[')
        {
            if(!search2(l))
            {
                flag=0;
                break;
            }
            
        }
        if(s[i]=='{')
        {
            if(!search3(l))
            {
                flag=0;
                break;
            }
            
        }
        i++;
    }
    if(flag==1)
        cout<<"yes";
    else
        cout<<"no";
}
