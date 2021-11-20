#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<string.h>
using namespace std;
char maps[10001][10001];
int visited[10001][10001];
int book[10001][10001];
int n, m, sum, maxsum, cnt = 0;
stack<int> Xs, Ys;
int ways[4][2] = { {1,0},{0,1},{0,-1},{-1,0} };
void dfs(int x, int y)
{
	int i, newx, newy;
	for (i = 0; i < 4; i++)
	{
		newx = x + ways[i][0];
		newy = y + ways[i][1];
		if (newx < 1 || newx > n || newy < 1 || newy > n) continue;
		if (visited[newx][newy]) continue;
		if (maps[x][y] == maps[newx][newy])
		{
			visited[newx][newy] = 1;
			dfs(newx, newy);
		}
	}
}
int main()
{
	int i, x, y, j, X, Y;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			cin >> maps[i][j];
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			//cout << maps[i][j] << endl;
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			if (maps[i][j] == '1')
			{
				cnt++;
				dfs(i, j);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}