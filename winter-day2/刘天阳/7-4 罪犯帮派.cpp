#include<bits/stdc++.h>
using namespace std;
vector<int> G[1009];
bool vis[1009];
int p[1009], t = 1, mid = 0;//a[i]表示编号为i的罪犯的帮派，t为帮派数目; 
void find(int k)
{	
	if(vis[k]) return;
	p[k] = t; vis[k] = 1;
	for (int i = 0; i < G[k].size(); i++)
	{
		if(!vis[G[k][i]])	find(G[k][i]);
	}
	return;
}
int main()
{
	int n,m,q;
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1 ; i <= n; i++)
	{
		if(!vis[i]) {
			mid = 0;
//			printf("i = %d\n",i);
			find(i);
			t++;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		int a, b;
		cin >> a >> b;
		if(p[a] == p[b] &&p[a]&&p[b]) cout << "In the same gang." << endl;
		else cout << "In different gangs." << endl;	
	}
	cout << t-1 << endl;
	return 0;
}
