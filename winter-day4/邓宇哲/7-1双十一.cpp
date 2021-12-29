#include <iostream>
#include <cstring>
using namespace std;
int map[200][200];
main()
{
	int v, e;
	while (cin >> v >> e)
	{
		memset(map, 0, sizeof(map));
		for (int t = 0; t < e; t++)
		{
			int i, j;
			cin >> i >> j >> map[i][j];
			map[j][i] = map[i][j];
		}
		for (int k = 0; k < v; k++)
		{
			for (int j = 0; j < v; j++)
			{
				for (int i = 0; i < v; i++)
				{
					if ((map[i][j] > map[i][k] + map[k][j] || map[i][j] == 0) && map[i][k] != 0 && map[k][j] != 0)
					{
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		int sum = 0;
		int minsum = 99999;
		int minn = 0;
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				sum += map[i][j];
			}
			if (minsum > sum)
			{
				minsum = sum;
				minn = i;
			}
			sum = 0;
		}
		cout << minn<<endl;
	}
}