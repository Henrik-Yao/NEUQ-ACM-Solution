/*给定n种物品（每种仅一个）和一个容量为c的背包，要求选择物品装入背包，使得装入背包中物品的总价值最大。

输入格式:
测试数据有多组，处理到文件尾。每组测试数据输入3行，第1行为两个整数n（1≤n≤400）和c (1≤c≤1500)，
分别表示物品数量与背包容量，第二行为n个物品的重量w 
i
​	
 （1≤i≤n），第三行为这n个物品的价值v 
i
​	
 （1≤i≤n）。物品重量、价值都为整数。

输出格式:
对于每组测试，在一行上输出一个整数，表示装入背包的最大总价值（结果保证在int范围内）。

*/
#include<iostream>
using namespace std;
const int w = 1501;
int wei[w];
int val[w];
int dp[w][w] = { {0} };
void qiudp(int n, int c);
int max(int a, int b);
int main()
{
	int n, c;

	while (cin >> n >> c)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> wei[i];
		}
		wei[0] = 0;
		val[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> val[i];
		}
		qiudp(n, c);
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				sum = max(sum, dp[i][j]);
			}
		}
		cout << sum << endl;
	}
	return 0;
}
void qiudp(int n, int c)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j < wei[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wei[i]] + val[i]);
			}
		}
	}
}
int max(int a, int b)
{
	return a > b ? a : b;
}