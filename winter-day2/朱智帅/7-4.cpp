#include<iostream>
using namespace std;
int nextlink[1005][1005] = { 0 };
int visited[1005] = { 0 };
int main()
{
	int n, m, q, i, j, k;
	cin >> n >> m >> q;
	for (i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		nextlink[a-1][b-1] = 1;
		nextlink[b-1][a-1] = 1;
	}
	for (i = 0; i < n; i++) nextlink[i][i] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (nextlink[j][i] && nextlink[i][k]) nextlink[j][k] = 1;
			}
		}
	}
	int cnt = 0;
	for (i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			cnt++;
			visited[i] = 1;
			for (j = i + 1; j < n; j++)
			{
				if (nextlink[i][j])
				{
					visited[j] = 1;
				}
			}
		}
	}
	for (i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		if (nextlink[x-1][y-1]) cout << "In the same gang." << endl;
		else cout << "In different gangs." << endl;
	}
	cout << cnt << endl;
	return 0;
}