#include <bits/stdc++.h>
using namespace std;
int g[209][209];
int main()
{
	int n, m; char c;
	while(cin >> n >> m)
	{
		getchar();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			 	if(i==j) g[i][j] = 0;
			 	else g[i][j] = 1006;
			 	
		for (int i = 0; i < n; i++)
		{
			int u, t, v;
			cin >> u >> t;
			while(t--)
			{
				cin >> v; g[u][v] = 1;
			}
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)	
//				 cout << g[i][j] << " ";
//				 cout << endl;
//				}		
		for (int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			if(g[a][b] != 1006) cout << g[a][b] << endl;
			else cout << "connection impossible" << endl;
		}
	}
	return 0;
}
