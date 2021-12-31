#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
typedef long long int ll;
ll a[1000100];
ll qiuhe(ll r);
ll jia(ll y, ll m);
ll lowbit(ll x);
ll n, q;

int main()
{
	
	ll* p;
	p = &a[0];
	cin >> n >> q;
	memset(p, 0, sizeof(a));
	
	for (ll i = 1;i <= n; i++)
	{
		ll temp;
		cin >> temp;
		jia(i, temp);
	}
	for (int j = 0; j < q; j++)
	{
		ll temp1;
		cin >> temp1;
		if (temp1 == 1)
		{
			ll temp2, temp3;
			cin >> temp2 >> temp3;
			jia(temp2, temp3);
		}
		else
		{
			ll temp4, temp5;
			cin >> temp4 >> temp5;
			cout << qiuhe(temp5) - qiuhe(temp4 - 1) << endl;
			
		}
	}
	return 0;
}

ll qiuhe(ll  r)
{
	ll sum = 0;
	while (r > 0)
	{
		sum += a[r];
		r -= lowbit(r);
	}
	return sum;
}
ll jia(ll y, ll m)
{
	while (y <=n)
	{
		a[y] += m;
		y += lowbit(y);
	}
	return 0;
}
ll lowbit(ll x)
{
	return x & (-x);
}