#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;
int d[10009], f[10009];
int g[10009][10009];
bool vis[10009];
int main()
{
	int n, e, u;
	cin >> n >> e >> u;
	for (int i = 0; i < n; i++) d[i] = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = INF;
	for (int i = 1; i <= e/2; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[b][a] = g[a][b] = c;
	}
	int  v; 
//	cin >> u >> v; 
	d[u] = 0;
	for (int i = 0; i < n; i++) f[i] = i;
	for (int i = 0; i < n; i++)
	{
		int x, m = INF;
		for (int y = 0;y < n; y++)
		{
			if(!vis[y] && d[y] <= m) m = d[x=y];
			vis[x] = 1;
			for (int y = 0; y < n; y++)
			{
				if(d[y] > d[x] + g[x][y])
				{
					d[y] = d[x] + g[x][y];
					f[y] = x;
				}
			}
		}
	}
//	for (int i = 0; i < n; i++) cout << f[i] << " " ;
//	cout << endl;
	int vv = v;
	int ans[1009], cnt = 0;
	while(f[v] != u)
	{
		cnt++;
		ans[cnt] = f[v];
		v = f[v];
	}
//	cout << u << "-->";
	ans[++cnt] = u;
	for (int i = cnt; i >= 1; i--) cout << ans[i] << "-->";
	cout << vv;
	cout << ":";
	cout << d[vv];
 	return 0;
}
