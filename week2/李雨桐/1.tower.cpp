#include <bits/stdc++.h>
using namespace std;

void tower(int n,string x,string y,string z)
{
    if(n==1)
        cout<<x<<"->"<<z<<endl;
    else
    {
        tower(n-1,x,z,y);
        cout<<x<<"->"<<z<<endl;
        tower(n-1,y,x,z);
    }
}

int main()
{
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;

    tower(n,a,b,c);

    return 0;
}
