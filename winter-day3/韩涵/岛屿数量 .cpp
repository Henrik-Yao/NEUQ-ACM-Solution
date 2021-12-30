#include<iostream>
using namespace std;

int maps[109][109];

void DFS(int x, int y)
{
	if (!maps[x][y])
		return;
	maps[x][y] = 0;
	DFS(x + 1, y);
	DFS(x, y + 1);
	DFS(x - 1, y);
	DFS(x, y - 1);
}

int main()
{
	int n, m, num = 0;
	cin >> n >> m;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			cin >> maps[x][y];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
		{
			if (maps[x][y] == 1)
			{
				DFS(x, y);
				num++;
			}
		}
	cout << num;
}