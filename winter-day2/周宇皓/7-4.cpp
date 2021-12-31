#include<bits/stdc++.h>
using namespace std;
int n,m,q,bin[1009];
int find(int x)
{
    if(x!=bin[x]) bin[x]=find(bin[x]);
    return bin[x];
}
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) bin[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        int a=find(x),b=find(y);
        if(a!=b) bin[a]=b;
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        int a=find(x),b=find(y);
        if(a==b) printf("In the same gang.\n");
        else printf("In different gangs.\n");
    }
    int ans=0;
    for(int i=1;i<=n;i++) 
    if(bin[i]==i) ans++;
    cout<<ans<<endl;
    return 0;
}
