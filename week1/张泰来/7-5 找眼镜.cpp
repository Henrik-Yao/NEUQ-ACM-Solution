#include <bits/stdc++.h>
using namespace std;
struct person{
	int type;
	char s[10005];
}p[100005];
int n,m,t,x,now;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",&p[i].type);
		scanf("%s",p[i].s);
	}
	now = 1;
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d",&t,&x);
		if (p[now].type + t == 1)
		{
			now += x % n;
			now %= n;
			if (!now) now = n;
		} else {
			now -= x % n;
			now = (now % n + n) % n;
			if (!now) now = n;
		}
	}
	printf("%s\n",p[now].s);
	return 0;
}

