#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009],n;
ll dfs(ll l,ll r)
{
    if(l==r) return a[l];
    ll mid=(l+r)/2;
    ll ansl=dfs(1,mid),ansr=dfs(mid+1,r);
    ll su=0,an=-1e9;
    for(ll i=mid;i>=l;i--)
    {
        su+=a[i];
        an=max(su,an);
    }
    ll sum=0,ans=-1e9;
    for(ll i=mid+1;i<=r;i++)
    {
        sum+=a[i];
        ans=max(ans,sum);
    }
    ll rea=max(ansl,ansr);
    rea=max(rea,an+max(ll(0),ans));
    rea=max(rea,ans+max(an,ll(0)));
    return rea;
}
int main()
{
    cin>>n;
    bool flag=0;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]>0)
        flag=1;
    }
    if(!flag)
    cout<<0<<endl;
    else 
    cout<<dfs(1,n)<<endl;
    return 0;
}
