// ?????????????????????这不是dfs????????????????????????
#include<iostream>
using namespace std;
int vis[101][101];//visited
int gs = 0;
int ma[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (!vis[x + dx[i]][y + dy[i]] && ma[x + dx[i]][y + dy[i]])
			dfs(x + dx[i], y + dy[i]);
	
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ma[i][j];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			if (!vis[x][y] && ma[x][y])
			{
				gs++;
				dfs(x, y);
			}
	cout << gs;
}
