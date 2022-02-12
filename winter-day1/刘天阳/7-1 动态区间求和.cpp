#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6;
long long a[N+9], t[N+9], n, m;
long long lowbit(long long a)	{return (a&(-a));}
void add(long long x, long long k)	{for(;x <= n; x += lowbit(x)) t[x] += k;}
long long ask(long long x)
{
	long long ans = 0;
	for(; x; x -= lowbit(x)) ans += t[x];
	return ans;
}
long long find(long long l, long long r)
{
	return ask(r)-ask(l-1);
}
int main()
{
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) 
	{
		cin >> a[i];
		for (long long j = i-lowbit(i)+1; j <= i; j++) t[i] += a[j];
	}
	long long ju, l, r;

	for (long long i = 1; i <= m; i++) 
	{
		cin >> ju >> l >> r;
		if(ju == 1) add(l,r);
		else 
		{
			cout << find(l, r) << endl;
		}
	}
	
	return 0;
}
