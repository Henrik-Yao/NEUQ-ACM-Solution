#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int u, v, val;
};
Edge edge[10009];
int g[1009][1009], p[1009];
bool cmp(Edge e1, Edge e2)
{
	return e1.val < e2.val;
}
int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		if(!g[a][b] || g[a][b] > c) g[a][b] = c;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if(g[i][j]) edge[++cnt].u = i, edge[cnt].v = j, edge[cnt].val = g[i][j]; 
		}
	int ans = 0, tmp = 0;
	sort(edge+1,edge+1+cnt, cmp);
	for (int i = 1; i <= cnt; i++)
	{
		int x = find(edge[i].u), y = find(edge[i].v);
		if(x != y)
		{
			tmp++;
			ans = max(ans, edge[i].val);
			p[x] = y;
		}
	}
	cout << tmp << " " << ans;
	return 0;
}
