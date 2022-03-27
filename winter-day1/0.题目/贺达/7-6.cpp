#include<bits/stdc++.h>
using namespace std;

stack<char> k;

int main()
{
    string s;
    cin>>s;
    int l=s.length();
    k.push(s[0]);
    for(int i=1;i<l;i++)
    {

        if((s[i]==k.top())&&(k.size()!=0))
        {
            k.pop();
        }
        else
        {
            k.push(s[i]);
        }
    }
    if(k.empty()==true)
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    return 0;
}
