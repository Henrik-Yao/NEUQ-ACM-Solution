#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, c, w[405], v[405], dp[405][405];
	while (cin >> n && cin >> c)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)cin >> w[i];
		for (int i = 1; i <= n; i++)cin >> v[i];
		for (int i = 1; i <= n; i++)//第i个物品
		{
			for (int j = c; j >= 0; j--)//背包容量
			{
				if (w[i] > j) dp[i][j] = dp[i - 1][j];//塞不下
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i] ] + v[i]);
				}
			}
		}
		cout << dp[n][c]<<endl;
	}
	return 0;
}