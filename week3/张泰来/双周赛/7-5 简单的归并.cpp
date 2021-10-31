#include <bits/stdc++.h>
using namespace std;
int T,n,m;
int a[105],b[105],c[205];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		int now1 = 1,now2 = 1;
		int cnt = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",a + i);
		}
		scanf("%d",&m);
		for (int i = 1;i <= m; i++)
		{
			scanf("%d",b + i);
		}
		while (now1 <= n && now2 <= m)
		{
			if (a[now1] <= b[now2])
			{
				c[++cnt] = a[now1];
				now1++;
			} else {
				c[++cnt] = b[now2];
				now2++;
			}
		}
		for (int i = now1;i <= n; i++)
			c[++cnt] = a[i];
		for (int i = now2;i <= m; i++)
			c[++cnt] = b[i];
		for (int i = 1;i <= cnt; i++)
		{
			printf("%d%c",c[i]," \n"[i == cnt]);
		}
	}
	return 0;
}
