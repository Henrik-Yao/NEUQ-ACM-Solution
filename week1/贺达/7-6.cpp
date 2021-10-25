#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,T;
    cin>>n>>T;
    int v[n];
    int t[n];
    int V[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i]>>t[i];
        if(t[i]<=T)
        {
            V[i]=v[i];
        }
        else
        {
            V[i]=v[i]-(t[i]-T);
        }
    }
    sort(V,V+n);
    cout<<V[n-1];

    return 0;
}
