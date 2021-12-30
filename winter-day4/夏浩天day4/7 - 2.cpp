#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int a, b;
int en = 99999;
bool vis[201];
vector<int> ma[201];
void dfs(int now, int cs)
{
	if (vis[now])return;
	if (now == b) { en = min(en, cs); return; }
	vis[now] = 1;
	for (auto lsz : ma[now])
		dfs(lsz,cs+1);
	vis[now] = 0;
}

int main() 
{
	int n;
	while ((cin >> n), n != EOF)
	{
		memset(vis, 0, 201);
		for (int i=0;i<201;i++)
			ma[i].clear();
		int m; cin >> m;
		while (n--)
		{
			int i, k; cin >> i >> k;
			while (k--)
			{
				int q;
				cin >> q;
				ma[i].push_back(q);
			}
		}
		while (m--)
		{
			en = 99999;
			cin >> a >> b;
			dfs(a, 0);

			if (en == 99999)cout << "connection impossible" << endl;
			else cout << en << endl;
		}
	}
}