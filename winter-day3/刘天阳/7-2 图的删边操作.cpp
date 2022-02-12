#include <bits/stdc++.h>
using namespace std;
const int N = 20009;
int g[N][N];
int vis[N];
int main()
{
	int n, e; cin >> n >> e;
	for (int i = 1; i <= e; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		g[a][b] = c;
		vis[a]++;
	}
	int k; cin >> k;
	while(k--) {
		int a, b; cin >> a >> b;
		g[a][b] = 0, vis[a]--;
	}
	for (int i = 0; i < n; i++)
	{
		if(!vis[i]) continue;
		printf("%d:", i);
		for (int j = 0; j < n; j++)
		{
			if(g[i][j]) printf("(%d,%d,%d)",i,j,g[i][j]);
		}
		cout << endl;
	}
	return 0;
}
