#include <bits/stdc++.h>
using namespace std;
int n,t,m;
int a[105];
int main()
{
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 1;i <= n; i++)
			scanf("%d",a + i);
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n; i++)
		{
			printf("%d%c",a[i]," \n"[i == n]);
		}
		scanf("%d",&m);
		for (int i = 1;i <= m; i++)
		{
			scanf("%d",&t);
			int pos = lower_bound(a + 1,a + n + 1,t) - a;
			if (pos > n || a[pos] != t) printf("0%c"," \n"[i == m]);
			else printf("%d%c",pos," \n"[i == m]);
		}
	}
	return 0;
}
