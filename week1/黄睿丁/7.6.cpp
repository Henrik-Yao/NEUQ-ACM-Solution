#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,T,i;
    cin>>n>>T;
    int m=-10000000000;
    for(i=0;i<n;i++)
    {
        int v,t;
        cin>>v>>t;
        if(T>=t)
            m=max(v,m);
        else
            m=max(v-(t-T),m);
    }
    cout<<m;
}
