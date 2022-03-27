#include <bits/stdc++.h>
using namespace std;
map<string,string>zidian;
int main()
{
    int n;
    int m;
    cin>>n>>m;
    while(n--)
    {
        string a,b;
        cin>>a;cin>>b;
        zidian[b]=a;
    }
    while(m--)
    {
        string x;
        cin>>x;
        if(zidian[x]=="")
        cout<<"eh\n";
        else 
        cout<<zidian[x]<<endl;
    }
    return 0;
}