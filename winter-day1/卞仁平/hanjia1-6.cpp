#include <bits/stdc++.h>
using namespace std;
void is(char a,char b)
{
    if(a!=b)cout<<"no";
}
int main()
{
    string x;
    cin>>x;
    int l=x.length();
    for(int i=0;i<l/2;i++)
    {
        if(x[i]!=x[l-i-1])
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}