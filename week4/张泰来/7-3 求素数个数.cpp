#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool vis[10000005];
int prime[1000005];
int main()
{
	scanf("%d",&n);
	for (int i = 2;i <= n; i++)
	{
		if (!vis[i])
		{
			prime[++cnt] = i;
		}
		for (int j = 1;j <= cnt && i * prime[j] <= n; j++)
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	printf("%d\n",cnt);
	return 0;
} 
