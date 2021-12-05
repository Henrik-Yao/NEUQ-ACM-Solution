#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[1005],dp[1005];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int ans = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",a + i);
			dp[i] = 1;
		}
		for (int i = 1;i <= n; i++)
		{
			for (int j = 1;j < i; j++)
			{
				if (a[i] > a[j])
				{
					dp[i] = max(dp[i],dp[j] + 1);
				}
			}
			ans = max(ans,dp[i]);
		}
        if (T > 0)  printf("%d\n\n",ans);
        else printf("%d\n",ans);
	}
	return 0;
} 
