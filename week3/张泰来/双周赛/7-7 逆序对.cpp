#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[1000005],b[1000005];
long long c[1000005];
int lowbits(int x)
{
	return x & (-x);
}
void update(int x,int val)
{
	for (int i = x;i <= n;i += lowbits(i))
	{
		c[i] += val;
	}
	return;
}
int query(int x)
{
	int sum = 0;
	for (int i = x;i;i -= lowbits(i))
	{
		sum += c[i];
	}
	return sum;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
		b[i] = a[i];
	}
	sort(b + 1,b + n + 1);
	for (int i = 1;i <= n; i++)
	{
		int pos = lower_bound(b + 1,b + n + 1,a[i]) - b;
		a[i] = pos;
	}
	for (int i = 1;i <= n; i++)
	{
		update(a[i],1);
		int t = query(a[i]);
		ans += i - t;
	}
	printf("%lld\n",ans);
	return 0;
}

