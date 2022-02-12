#include <bits/stdc++.h>
using namespace std;
int g[109][109];
int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if(i == j) g[i][j] = 0;
				else g[i][j] = 10001;
				
		for (int i = 1; i <= m; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			g[a][b] = g[b][a] = c;
		}
		
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
//		for (int i = 0; i < n; i++)
//			{
//					for (int j = 0; j < n; j++)
//					cout << g[i][j] << " ";
//					cout << endl;
//			}
		int sum = 0, ans = 10001, t = 0;
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			for (int j = 0; j < n; j++)
				sum += g[i][j];
//			printf("i = %d, sum = %d\n",i,sum);
			if(sum < ans) {
				ans = sum, t = i;
			}
		}
		cout << t << endl;	
		
	}
	return 0;
}
