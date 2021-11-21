#include<iostream>
using namespace std;
int jl[1005][1005];
int visited[1005][1005], qwer[1005][1005], result[100005];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int qw, n, m;
int bfs(int x, int y)
{
	int ans = 1;
	visited[x][y] = 1;
	for (int q = 0; q < 4; q++)
	{
		int x1 = x + dx[q], y1 = y + dy[q];
		if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= n && visited[x1][y1] == 0 && jl[x][y] != jl[x1][y1])
		{
			qwer[x1][y1] = qw;
			ans += bfs(x1, y1);
		}
	}
	return ans;
}
int main()
{
	string a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		for (int j = 0; j < n; j++)
		{
			if (a[j] == '0')
				jl[i][j+1] = 0;
			else
				jl[i][j+1] = 1;
		}

	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (!visited[x][y])
		{
			qw++;
			qwer[x][y] = qw;
			result[qw] = bfs(x, y);
			if (i == 1)
				cout << result[qw];
			else
				cout << endl << result[qw] ;
		}
		else
		{
			if (i == 1)
				cout << result[qwer[x][y]];
			else
				cout << endl << result[qwer[x][y]];
		}
	}
}