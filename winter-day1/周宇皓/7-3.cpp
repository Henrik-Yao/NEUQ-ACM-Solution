#include<bits/stdc++.h>
using namespace std;
int ne[1009],fron[1009];
int n,m,k;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<n;i++) ne[i]=i+1;
    ne[n]=1;
    for(int i=2;i<=n;i++) fron[i]=i-1;
    fron[1]=n;
    int now=1;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<m;j++) now=fron[now];
        }
        else if(i%2==0) 
        {
            for(int j=1;j<k;j++) now=ne[now];
        }
        cout<<now<<' ';
        ne[fron[now]]=ne[now];
        fron[ne[now]]=fron[now];
        if(i%2==1) now=fron[now];
        else now=ne[now];
    }
    return 0;
}
