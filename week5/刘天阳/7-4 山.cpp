#include <iostream>
using namespace std;

const int N = 2009;
bool G[N][N], v[N][N];
int n, m, d[][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int x, int y) 
{
	v[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + d[i][0], yy = y + d[i][1];
		if(xx == 0 || yy == 0) continue;
		if(xx > n || yy > m) continue;
		if(v[xx][yy]) continue;
		if(G[xx][yy] == G[x][y]) dfs(xx, yy);
	}
}

int main ()
{
	int ans = 0;;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			cin >> G[i][j];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++)
			if(!v[i][j]) 
			{
				if(G[i][j]) ans++;
				dfs(i, j);
			}
	cout << ans;
	return 0;
}
