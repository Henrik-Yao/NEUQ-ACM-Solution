#include <bits/stdc++.h>
using namespace std;
int m,n,ans;
int martix[2005][2005];
int fa[4000005];
int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void unionn(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if (a == b) return;
	fa[a] = b;
	return;
}
int get_id(int x,int y)
{
	return (x - 1) * n + y;
}
int main()
{
	scanf("%d%d",&m,&n);
	
	for (int i = 1;i <= n * m; i++)
	{
		fa[i] = i;
	}
	for (int i = 1;i <= m; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			scanf("%d",&martix[i][j]);
		}
	}
	for (int i = 1;i <= m; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			if (!martix[i][j]) continue;
			int t = get_id(i,j);
			int x = get_id(i + 1,j);
			int y = get_id(i,j + 1);
			if (i != m && martix[i + 1][j]) unionn(t,x);
			if (j != n && martix[i][j + 1]) unionn(t,y);
		}
	}
	for (int i = 1;i <= m; i++)
	{
		for (int j = 1;j <= n; j++)
		{
			if (!martix[i][j]) continue;
			int num = get_id(i,j);
			if (find(num) == num) ans++;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
