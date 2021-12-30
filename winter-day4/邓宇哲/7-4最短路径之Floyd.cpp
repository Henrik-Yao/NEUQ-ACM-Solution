#include <iostream>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
void findpath3(int, int);
int path[200][200];
int map[200][200];
int maxi, maxj, maxn = -1;
set<int> cache;
main()
{
	int v, e;
	cin >> v >> e;

	memset(map, -1, sizeof(map));
	memset(path, -1, sizeof(path));

	for (int t = 0; t < e; t++)
	{
		int i, j;
		cin >> i >> j >> map[i][j];
	}
	for (int i = 0; i < v; i++)
	{
		map[i][i] = 0;
	}
	for (int k = 0; k < v; k++)
	{
		for (int j = 0; j < v; j++)
		{
			for (int i = 0; i < v; i++)
			{
				if ((map[i][j] > map[i][k] + map[k][j] || map[i][j] == -1) && map[i][k] != -1 && map[k][j] != -1)
				{
					map[i][j] = map[i][k] + map[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << x << "->";
		if (map[x][y] == -1)
		{
			cout << y << ':' << -1 << endl;
			continue;
		}
		findpath3(x, y);
		cout << y << ':' << map[x][y] << endl;
	}
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
		{
			if (maxn < map[i][j])
			{
				maxn = map[i][j];
				maxi = i;
				maxj = j;
			}
		}
	cout << maxi << "->";
	findpath3(maxi, maxj);
	cout << maxj << ':' << maxn;
}
void findpath3(int x, int y)
{
	if (path[x][y] == -1)
	{
		return;
	}
	findpath3(x, path[x][y]);
	cout << path[x][y] << "->";
	findpath3(path[x][y], y);
}
