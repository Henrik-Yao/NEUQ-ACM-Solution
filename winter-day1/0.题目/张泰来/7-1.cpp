#include <bits/stdc++.h>
using namespace std;
int a[1000005];
long long c[1000005];
int n,q,x,type,c1,l,r;
long long ans;
int lowbits(int x)
{
	return x & (-x);
}
void add(int x,int val)
{
	for (int i = x;i <= n; i += lowbits(i))
	{
		c[i] += val; 
	}
	return;
}
long long query(int x)
{
	long long sum = 0;
	for (int i = x;i;i -= lowbits(i))
	{
		sum += c[i];
	}
	return sum;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
		add(i,a[i]);
	}
	for (int i = 1;i <= q; i++)
	{
		scanf("%d",&type);
		if (type == 1)
		{
			scanf("%d%d",&x,&c1);
			add(x,c1);
		} else {
			scanf("%d%d",&l,&r);
			ans = query(r) - query(l - 1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
