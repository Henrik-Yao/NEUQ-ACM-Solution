#include <bits/stdc++.h>
using namespace std;
int n;
long long ans,t;
long long dp[10005];
int main()
{
	memset(dp,0x83,sizeof(dp));
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%lld",&t);
		dp[i] = max(t,dp[i - 1] + t);
		ans = max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
