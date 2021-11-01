#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000009],c[1000009],n,cnt;
void dfs(ll l,ll r)
{
    if(l==r) return ;
    ll mid=(l+r)/2;
    dfs(l,mid);
    dfs(mid+1,r);
    ll lef=l,rig=mid+1,pos=lef;
    while(lef<=mid&&rig<=r)
    {
        if(a[lef]<=a[rig])
        {
            c[pos++]=a[lef];
            lef++;
        }
        else 
        {
            c[pos++]=a[rig];
            rig++;
            cnt+=mid-lef+1;
        }
    }
    while(lef<=mid)
    {
        c[pos++]=a[lef];
        lef++;
    }
    while(rig<=r)
    {
        c[pos++]=a[rig];
        rig++;
    }
    for(ll i=l;i<=r;i++)
    {
        a[i]=c[i];
    }
}
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    dfs(1,n);
    cout<<cnt<<endl;
    return 0;
}
