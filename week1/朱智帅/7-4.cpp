#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
int v[100001], t[100001];
int dp[1001];
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	int n, i, j, sum = 1;
	cin >> n;
	dp[1] = 1;
	for (i = 2; i <= n; i++)
	{
		dp[i] = 1;
		int k = sqrt(i) + 1;
		for (j = 1; j < k; j++)
		{
			if (j == 1) dp[i]++;
			else if (i % j == 0)
			{
				if (i / j == j) dp[i] = dp[i] + dp[j];
				else dp[i] = dp[i] + dp[j] + dp[i / j];
			}
		}
	}
	cout << dp[n];
	return 0;
}