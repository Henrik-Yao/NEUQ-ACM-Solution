#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<string.h>
using namespace std;
char maps[1001][1001];
int visited[1001][1001];
int book[1001][1001];
int n, m, sum, maxsum;
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
		if (maps[x][y] != maps[newx][newy])
		{
			Xs.push(newx), Ys.push(newy);
			visited[newx][newy] = 1;
			sum++;
			dfs(newx, newy);
		}
	}
}
int main()
{
	int i, x, y, j, X, Y;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> maps[i] + 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			sum = 1, maxsum = 0;
			dfs(i, j);
			book[i][j] = sum;
			while (Xs.size())
			{
				X = Xs.top(), Y = Ys.top();
				book[X][Y] = sum;
				Xs.pop(), Ys.pop();
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		cout << book[x][y] << endl;
	}
	return 0;
}