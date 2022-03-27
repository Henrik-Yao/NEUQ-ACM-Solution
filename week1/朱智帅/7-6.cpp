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
int dp[1000001];
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	int n, T, i, j, m, M;
	cin >> n >> T;
	for (i = 0; i < n; i++)
	{
		cin >> v[i] >> t[i];
	}
	M = T - t[0];
    if(M>=0) M=v[0];
    else M=M+v[0];
	for (i = 1; i < n; i++)
	{
		m = T - t[i];
        if(m>=0) m=v[i];
        else m=m+v[i];
		if (m > M) M = m;
	}
    /*
	for (i = 0; i <= T; i++)
	{
		dp[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = T; j >= 0; j--)
		{
			if (j >= t[i])
			{
				dp[j] = max(dp[j - t[i]] + v[i], dp[j]);
			}
			else
			{
				if (v[i] + j - t[i] > 0) dp[j] = max(dp[0] + v[i] + j - t[i], dp[j]);
			}
		}
	}*/
	//if (dp[T] == 0) dp[T] = M;
	cout << M;
	return 0;
}

