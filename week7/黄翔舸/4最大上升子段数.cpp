/*��������һ��������T����ʾ�������ݵ�������Ȼ����T��������ݡ�
ÿ��������ݵ�һ������һ������ n��1��n��1000�����ڶ�������n�����������ݷ�Χ����[0��10000]��
����֮����һ���ո�ָ���

�����ʽ:
����ÿ����ԣ����n���������������е�����������еĳ��ȡ�ÿ������Ե����֮����һ�����С�*/
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
