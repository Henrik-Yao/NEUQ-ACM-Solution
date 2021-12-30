#include <bits/stdc++.h>
using namespace std;
int n,cnt;
long long ans;
long long a[100005],b[100005],c[200005];
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%lld",a + i);
	}
	
	for (int i = 1;i <= n; i++)
	{
		scanf("%lld",b + i);
	}
	int pointer1 = 1,pointer2 = 1;
	c[0] = -1e18;
	while (pointer1 <= n && pointer2 <= n)
	{
		if (a[pointer1] < b[pointer2]) 
		{
			c[++cnt] = a[pointer1];
			pointer1++;
		} else {
			c[++cnt] = b[pointer2];
			pointer2++;
		}
	}
	for (int i = pointer1;i <= n; i++)
		c[++cnt] = a[i];
	for (int i = pointer2;i <= n; i++)
		c[++cnt] = b[i];
	int t = (cnt + 1) / 2;
	printf("%lld\n",c[t]);
	return 0;
}

