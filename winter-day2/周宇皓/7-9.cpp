#include<bits/stdc++.h>
using namespace std;
int a[200009];
int b[19],c[19],n;
void dfs(int l,int r,int num,int lef,int rig)
{
    int gen=c[rig];
    a[num]=gen;
    if(l>=r) return ;
    if(lef>=rig) return ;
    // cout<<l<<' '<<r<<' '<<num<<' '<<lef<<' '<<rig<<endl;
    int i;
    for(i=l;i<=r;i++)
    {
        if(b[i]==gen) break;
    }
    int ll=i-l,rr=r-i;
    if(ll>0) dfs(l,i-1,num*2,lef,lef+ll-1);
    if(rr>0) dfs(i+1,r,num*2+1,lef+ll,rig-1);
}
void hou(int num)
{
    if(a[num]==0) return ;
    cout<<a[num]<<' ';
    hou(num*2);
    hou(num*2+1);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    dfs(1,n,1,1,n);
    hou(1);
    return 0;
}
