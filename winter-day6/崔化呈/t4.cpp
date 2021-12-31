#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>a,b;
ll n,ans;
void mergesort(ll l,ll r)
{
    if(l == r){return;}
    ll m = (l + r)/2;
    mergesort(l,m);
    mergesort(m + 1,r);
    ll i = l,j = m + 1,k = l;
    while(i <= m && j <= r)
	{
        if(a[i] <= a[j])
		{
            b[k++] = a[i++];
        }
        else
		{
            b[k++] = a[j++];
            ans += m - i + 1;
        }
    }
    while(i <= m){b[k++] = a[i++];}
    while(j <= r){b[k++] = a[j++];}
    for(ll p = l;p <= r;p++){a[p] = b[p];}
}
int main()
{
    scanf("%lld",&n);
    a.resize(n + 1);
	b.resize(n + 1);
    for(ll i = 1;i <= n;i++)
	{
        scanf("%lld",&a[i]);
    }
    mergesort(1,n);
    printf("%lld\n",ans);
    return 0;
}
