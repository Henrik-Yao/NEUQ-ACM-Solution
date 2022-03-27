#include<bits/stdc++.h>
using namespace std;
int a[200009];
int b[19],c[19],n;
void dfs(int l,int r,int num,int lef,int rig)
{
    int gen=b[l];
    a[num]=gen;
    if(l==r) return ;
    int i;
    for(i=lef;i<=rig;i++)
    {
        if(c[i]==gen) break;
    }
    int ll=i-lef,rr=rig-i;
    if(ll>0) dfs(l+1,l+ll,num*2,lef,i-1);
    if(rr>0) dfs(l+ll+1,r,num*2+1,i+1,rig);
}
void hou()
{
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<a[node]<<' ';
        if(a[node*2]!=0) q.push(node*2);
        if(a[node*2+1]!=0) q.push(node*2+1);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    dfs(1,n,1,1,n);
    hou();
    return 0;
}
