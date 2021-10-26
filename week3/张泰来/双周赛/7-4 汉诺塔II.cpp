#include <bits/stdc++.h>
using namespace std;
int n;
__int128 dp[75][3];
void print(__int128 x)
{
	int ans[45];
	ans[0] = 0;
	while (x)
	{
		ans[++ans[0]] = x % 10;
		x /= 10;
	}
	for (int i = ans[0];i >= 1; i--)
	{
		cout << ans[i];
	}
	cout << endl;
}
int main()
{
	
	dp[1][1] = dp[1][2] = 1;
	for (int i = 2;i <= 64; i++)
	{
		dp[i][1] = 2 * dp[i - 1][1] + 1;
		dp[i][2] = 1e18;
		for (int j = i - 1;j >= 1; j--)
		{
	//		if (dp[i - 1 - j][1] >= dp[i][2]) continue;
			dp[i][2] = min(dp[i][2],2 * dp[j][2] + 2 * dp[i - 1 - j][1] + 1);
		}
	}
	while (cin >> n)
	{
		print(dp[n][2]);
	//	cout << dp[n][2] << endl;
	}
	return 0;
}
