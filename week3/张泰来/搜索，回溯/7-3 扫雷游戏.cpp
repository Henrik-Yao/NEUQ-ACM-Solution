#include <bits/stdc++.h>
using namespace std;
int n,m,k,l,x,y,cnt;
int martix[25][25],paint[25][25];
int dx[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool check[25][25],vis[25][25];
bool in(int tx,int ty)
{
	return tx >= 0 && tx < n && ty >= 0 && ty < m;
}
void dfs(int x,int y)
{
	cnt++;
	vis[x][y] = 1;
	if (martix[x][y])
	{
		paint[x][y] = martix[x][y];
		return;
	}
	paint[x][y] = 0;
	for (int i = 0;i < 8; i++)
	{
		int tx = x + dx[i][0];
		int ty = y + dx[i][1];
		if (!in(tx,ty) || vis[tx][ty]) continue;
		dfs(tx,ty);
	}
	return;
}
void print()
{
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < m; j++)
		{
			printf("%d ",paint[i][j]);
		}
		printf("\n");
	}
	return;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&l);
	for (int i = 1;i <= k; i++)
	{
		scanf("%d%d",&x,&y);
		check[x][y] = 1;
	}
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < m; j++)
		{
			paint[i][j] = -1;
		}
	}
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < m; j++)
		{
			int sum = 0;
			for (int k = 0;k < 8; k++)
			{
				int tx = i + dx[k][0];
				int ty = j + dx[k][1];
				if (!in(tx,ty)) continue;
				if (check[tx][ty]) sum++;
			}
			martix[i][j] = sum;
		}
	}
	for (int i = 1;i <= l; i++)
	{
		scanf("%d%d",&x,&y);
		if (vis[x][y]) continue;
		if (check[x][y])
		{
			printf("You lose\n");
			return 0;
		}
		dfs(x,y);
		print();
		if (cnt == n * m - k) 
		{
			printf("You win\n");
			return 0;
		}
		printf("\n"); 
	}
	return 0;
}
