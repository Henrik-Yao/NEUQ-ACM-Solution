#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t, n,dp[1001],a[1001],maxa;
	cin >> t;
	while (t--)
	{
		maxa = 1;
		memset(dp, 1, sizeof(dp));
		memset(a, -1, sizeof(a));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			dp[i] = 1;
			for (int j = i-1; j >= 1; j--)//向前遍历
			{
				if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
			maxa = max(dp[i], maxa);
		}
		cout << maxa << endl;
		if(t>0)cout << endl;
	}
	return 0;
}