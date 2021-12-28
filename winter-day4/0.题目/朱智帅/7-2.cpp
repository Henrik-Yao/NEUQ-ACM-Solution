#include<iostream>
using namespace std;
int main()
{
	int n, e, i, j, k, a, b, w;
	while (cin >> n >> e)
	{
		if (!n || !e) continue;
		int Dis[201][201] = { 0 };
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Dis[i][j] = 1000;
			}
		}
		
		for (i = 0; i < n; i++)
		{
			cin >> a >> w;
			for (j = 0; j < w; j++)
			{
				cin >> b;
				Dis[a][b] = 1;
			}
			Dis[n][n] = 0;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					if (Dis[j][k] > Dis[j][i] + Dis[i][k]) Dis[j][k] = Dis[j][i] + Dis[i][k];
				}
			}
		}
		for (i = 0; i < e; i++)
		{
			cin >> a >> b;
			if (Dis[a][b] != 1000) cout << Dis[a][b] << endl;
			else cout << "connection impossible" << endl;
		}
	}
	return 0;
}