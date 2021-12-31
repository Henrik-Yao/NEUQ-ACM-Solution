#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int d[][2] = {{0,1},{0,-1},{-1,0},{1,0}};
bool g[N][N], vis[N][N];
int ans = 0;	int n, m; 
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + d[i][0], yy = y + d[i][1];
		if(xx == 0 || yy == 0) continue;
		if(xx > n || yy > m) continue;
		if(vis[xx][yy]) continue;
		if(g[xx][yy] == g[x][y]) dfs(xx, yy);
	}
}
int main()
{
cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> g[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(!vis[i][j]&&g[i][j]) ans++,dfs(i,j);
	cout << ans;
	return 0;
}
