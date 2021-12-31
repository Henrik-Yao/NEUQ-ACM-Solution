#include <bits/stdc++.h>
using namespace std;

const int N = 20009;
vector<int>G[N];
bool vis[N];

void dfs(int n) 
{
	vis[n] = 1;
	printf("%d ", n);
	for (int i = 0; i < G[n].size(); i++) 
		if(!vis[G[n][i]]) dfs(G[n][i]);
}

int main ()
{
	int n , e;
	cin >> n >> e;
	
	for (int i = 1; i <= e; i++) 
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	
	for (int i = 0; i < n; i++) 
		sort(G[i].begin(), G[i].end());
	
	for (int i = 0; i < n; i++) 
		if(!vis[i]) dfs(i);
	
	
	return 0;
}
