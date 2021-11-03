#include <bits/stdc++.h>
using namespace std;
int T;
int f[45];
int main()
{
	f[1] = f[2] = 1;
	for (int i = 3;i <= 40; i++)
		f[i] = f[i - 1] + f[i - 2];
	f[1] = 0;
	scanf("%d",&T);
	while (T--)
	{
		int t;
		scanf("%d",&t);
		printf("%d\n",f[t]);
	}
	return 0;
}
