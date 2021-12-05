#include <bits/stdc++.h>
using namespace std;
int n,c,ans;
int w[405],v[405];
int dp[1505];
int main()
{
	while (scanf("%d",&n) != EOF)
	{
		ans = 0;
		scanf("%d",&c);
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",w + i);
		}
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",v + i);
		}
		
		memset(dp,0x83,sizeof(dp));
		dp[0] = 0;
		
		for (int i = 1;i <= n; i++)
		{
			for (int j = c;j >= w[i]; j--)
			{
				dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
			}
		}
		for (int i = 1;i <= c; i++)
		{
			ans = max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
}
