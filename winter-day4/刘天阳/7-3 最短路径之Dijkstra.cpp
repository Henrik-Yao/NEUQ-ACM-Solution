#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8+7;
int f[1009], g[1009][1009], d[1009];
bool vis[1009];
int main()
{
	int n, e;
	cin >> n >>  e;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(i!=j )g[i][j] = INF;
			else g[i][j] = 0;
	for (int i = 1; i <= e/2; i++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = c;
	}
	int u, v; cin >> u >> v;
	if(u == v)
	{
		cout << u << "-->" << v << ":0";
		return 0;
	}
	for (int i = 0; i < n; i++) d[i] = INF;
	d[u] = 0;
	for (int i = 0; i < n; i++)
	{
		f[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		int x, m = INF;
		for (int j = 0; j < n; j++) if(!vis[j] && d[j] <= m) m = d[x = j];
		vis[x] = true;
		for (int j = 0; j < n; j++)
		{
			if(d[j] > d[x] + g[x][j])
			{
				d[j] = d[x] + g[x][j];
				f[j] = x;
			}
		}
	}
	int vv = v;
	int ans[1009], cnt = 0;
	ans[++cnt] = v;
	while(f[v] != -1)
	{
		ans[++cnt] = f[v];
		v = f[v];
	}
//	cout << u << "-->";
	for (int i = cnt; i > 1; i--)
	{
		cout << ans[i] << "-->";
	}
	cout << ans[1] << ":";
	cout << d[vv];
	return 0;
}
