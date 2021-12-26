#include<bits/stdc++.h>
using namespace std;
#define N 100
int v[N];
int main() {
    int n,m,q;
    int t = 0;
    cin>>n>>m>>q;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        if(v[a]==0&&v[b]==0)
        {
            t++;
            v[a] = t;
            v[b] = t;
        } else if(v[a]==0) v[a] = v[b];
        else v[b] = v[a];
    }
    for(int i = 0; i < q; i++)
    {
     int a,b;
     cin>>a>>b;
     if(v[a]==v[b])cout<<"In the same gang."<<endl;
     else cout<<"In different gangs."<<endl;
    }
    for(int i = 1; i <= n; i++)
    {
        if(v[i]==0)t++;
    }
    cout<<t<<endl;
    return 0;
}
