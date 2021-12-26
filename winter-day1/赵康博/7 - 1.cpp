#include <bits/stdc++.h>
using  namespace  std;
#define N 100000000
struct tr{
    int l,r;
    long long sum;
}s[N];
int f[N];

void build(int u,int l,int r)
{
    if(l==r)s[u] = {l,r,f[l]};
    else
    {
        s[u]  = {l,r};
        int mid = (l+r)/2;
        build(2*u,l,mid);
        build(2*u+1,mid+1,r);
        s[u].sum = s[u*2].sum + s[2*u+1].sum;
    }
}
long long h(int u,int l,int r)
{
    if(s[u].l>=l&&s[u].r<=r)return s[u].sum;
    else
    {
        int mid = (s[u].r+s[u].l)/2;
        long long sum = 0;
        if(l<=mid)sum+=h(2*u,l,r);
        if(r>mid)sum+=h(2*u+1,l,r);
        return sum;
    }
}
void quir(int u,int x,int t)
{
    if(s[u].r==s[u].l)s[u].sum+=t;
    else
    {
        int mid = (s[u].l+s[u].r)/2;
        if(x<=mid)quir(2*u,x,t);
        else quir(2*u+1,x,t);
        s[u].sum = s[2*u].sum + s[2*u+1].sum;
    }
}
int main()
{
    int n,p;
    cin>>n>>p;
    for(int i = 1; i <= n; i++)cin>>f[i];
    build(1,1,n);
    for(int i = 1; i <= p; i++)
    {
        int t,t1,t2;
        cin>>t>>t1>>t2;
        if(t==1){
            quir(1,t1,t2);
        } else
        {
            cout<<h(1,t1,t2)<<endl;
        }
    }
    return  0;
}