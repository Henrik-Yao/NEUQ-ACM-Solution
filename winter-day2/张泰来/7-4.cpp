#include <bits/stdc++.h>
using namespace std;
int n,m,q,a,b,ans;
int fa[1005];
int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void unionn(int x,int y)
{
	int fax = find(x);
	int fay = find(y);
	if (fax == fay) return;
	fa[fax] = fay;
	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d",&a,&b);
		unionn(a,b);
	}
	for (int i = 1;i <= q; i++)
	{
		scanf("%d%d",&a,&b);
		if (find(a) == find(b)) printf("In the same gang.\n");
		else printf("In different gangs.\n");
	}
	for (int i = 1;i <= n; i++)
	{
		if (find(i) == i) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
