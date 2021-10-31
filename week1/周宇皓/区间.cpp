#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
bool qian[100009],hou[100009];
ll qia[1000009],h[1000009];
ll a[1000009];
int main()
{
    cin>>n;
    for(ll i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
    {
        if(qian[a[i]]==0)
        {
            qian[a[i]]=1;
            qia[i]=qia[i-1]+1;
        }
        else 
        qia[i]=qia[i-1];
    }
    for(ll i=n;i>=1;i--)
    {
        if(hou[a[i]]==0)
        {
            hou[a[i]]=1;
            h[i]=h[i+1]+1;
        }
        else 
        h[i]=h[i+1];
    }
    ll maxn=-1;
    for(ll i=1;i<=n;i++)
    {
        maxn=max(maxn,qia[i]+h[i+1]);
    }
    cout<<maxn<<endl;
    return 0;
}
