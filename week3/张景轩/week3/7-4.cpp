#include<iostream>
using namespace std;
int disx[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
char s[1005][1005];
bool check[1005][1005],visit[1005][1005];
int tot[1005][1005],num[1000005];
int n,m,x,y,cnt;
bool in(int tx,int ty)
{
	return tx >= 0 && tx < n && ty >= 0 && ty < n;
}
void dfs(int x,int y,int id)
{
	tot[x][y] = id;
	num[id]++;
	visit[x][y] = 1;
	for (int i = 0;i < 4; i++)
	{
		int tx = x + disx[i][0];
		int ty = y + disx[i][1];
		if ((!in(tx,ty)) || visit[tx][ty] || (check[x][y] == check[tx][ty])) continue;
		dfs(tx,ty,id);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n; i++)
	{
		scanf("%s",s[i]);
	}
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			check[i][j] = s[i][j] - '0';
		}
	}
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			if (visit[i][j]) continue;
			cnt++;
			dfs(i,j,cnt);
		}
	}
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d",&x,&y);
		int t = tot[x - 1][y - 1];
		printf("%d\n",num[t]);
	}
	return 0;
}

//深度优先遍历，找到每个格子属于哪个块和所含格子数目