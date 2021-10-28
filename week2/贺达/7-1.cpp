#include<bits/stdc++.h>
using namespace std;

void hlt(int n,string a,string b,string c)
{
    if(n==1)
    {
        cout<<a<<"->"<<c<<endl;
    }
    else
    {
        hlt(n-1,a,c,b);
        cout<<a<<"->"<<c<<endl;
        hlt(n-1,b,a,c);
    }
}

int main()
{
    int n;
    string a,b,c;
    cin>>n>>a>>b>>c;
    hlt(n,a,b,c);
    return 0;
}
