#include <bits/stdc++.h>
using namespace std;
int n,m,sx,sy,tx,ty,cnt,cnt2;
int martix[1005][1005],lists[1000005][2],path[1000005][2],ans[1005][1005];
int dx[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool in(int x,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void dfs(int x,int y)
{
	if (x == tx && y == ty)
	{
		for (int i = 1;i <= cnt; i++)
		{
			cnt2 = cnt;
			path[i][0] = lists[i][0];
			path[i][1] = lists[i][1];
		}
		return;
	}
	for (int i = 0;i < 4; i++)
	{
		int tx = x + dx[i][0];
		int ty = y + dx[i][1];
		if (!in(tx,ty) || martix[tx][ty] == -1 || ans[tx][ty] <= ans[x][y] + martix[tx][ty]) continue;
		ans[tx][ty] = ans[x][y] + martix[tx][ty];
		lists[++cnt][0] = tx; lists[cnt][1] = ty;
		dfs(tx,ty);
		cnt--;
	}
	return;
}
int main()
{
	scanf("%d%d",&m,&n);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < m; j++)
		{
			scanf("%d",&martix[i][j]);
		}
	}
	n -= 2; m -= 2;
	for (int i = 1;i <= n; i++)
	{
		for (int j = 1;j <= m; j++)
		{
			ans[i][j] = 65535;
		}
	}
	ans[sx][sy] = martix[sx][sy];
	lists[++cnt][0] = sx; lists[cnt][1] = sy;
	dfs(sx,sy);
	for (int i = cnt2;i >= 1; i--)
	{
		printf("(%d %d)",path[i][0],path[i][1]);
	}
	printf("\n");
	return 0;
}
