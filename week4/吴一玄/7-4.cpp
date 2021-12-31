#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Pow(ll a, ll b, ll p)
{
	ll ans = 1 % p;
	for(; b; b >>= 1)
	{
		if(b & 1) ans = ans * a % p;
		a = a * a % p;
	}
	return ans;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		ll a, b, p;
		scanf("%lld %lld %lld", &a, &b, &p);
		printf("%lld\n", Pow(a, b, p));
	}
	return 0;
}