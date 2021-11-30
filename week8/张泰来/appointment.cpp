#include <bits/stdc++.h>
using namespace std;
struct schedule{
	int l,r;
}p[1000005];
int n,T,ans;
int dp[35];
bool cmp(schedule &x,schedule &y)
{
	if (x.l != y.l) return x.l < y.l;
	return (x.r - x.l) < (y.r - y.l);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans = 0;
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for (int i = 1;i <= n; i++)
		{
			scanf("%d%d",&p[i].l,&p[i].r);
		}
		sort(p + 1,p + n + 1,cmp);
		for (int i = 1;i <= n; i++)
		{
			for (int j = 0;j <= p[i].l; j++)
			{
				dp[p[i].r] = max(dp[p[i].r],dp[j] + 1);
			}
		}
		for (int i = 0;i < 24; i++)
			ans = max(ans,dp[i]);
		printf("%d\n",n - ans);
	}
	return 0;
}
