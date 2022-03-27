#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[55];
int main()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4;i <= 50; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (scanf("%d",&n) != EOF)
		printf("%lld\n",dp[n]);
	return 0;
}
