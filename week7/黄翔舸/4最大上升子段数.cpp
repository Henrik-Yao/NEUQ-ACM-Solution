/*首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。
每组测试数据第一行输入一个整数 n（1≤n≤1000），第二行输入n个整数，数据范围都在[0，10000]，
数据之间以一个空格分隔。

输出格式:
对于每组测试，输出n个整数所构成序列的最长有序子序列的长度。每两组测试的输出之间留一个空行。*/
#include<iostream>
#include<algorithm>
using namespace std;
int max(int a, int b);
int a[1001];
int dp[1001];
int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		for (int u = 0; u < n; u++)
		{
			if (u == 0)
			{
				dp[u] = 1;

			}
			else
			{
				dp[u] = 1;
				int flag = 0;
				for (int y = 0; y < u; y++)
				{

					if (a[u] > a[y])
					{
						flag++;
						dp[u] = max(dp[y], dp[u]);

					}

				}
				if (flag)
				{
					dp[u]++;
				}
			}
		}
		sort(dp, dp + n, less<int>());
		cout << dp[n - 1] << endl;
		if (i != t)
		{
			cout << endl;
		}
	}



	return 0;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
