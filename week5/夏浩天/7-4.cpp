#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
bool vis[2001][2001];
int mapp[2001][2001];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int m, n;
int gs;//¸öÊý
void dfs(int x, int y)
{
	if (y < 0 || x >= m || y >= n || x < 0 || vis[x][y] || !mapp[x][y])return;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int lx = x + dx[i], ly = y + dy[i];
		dfs(lx, ly);
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> mapp[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (mapp[i][j] && !vis[i][j])
			{
				dfs(i, j);
				gs++;
			}
		}
	cout << gs;
}