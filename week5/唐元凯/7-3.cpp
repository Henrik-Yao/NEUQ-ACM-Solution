#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int>side[20005];
bool vis[20005];

void dfs(int cur) {
	cout << cur << " ";
	vis[cur] = 1;
	for (int i = 0,length=side[cur].size(); i < length; i++)
	{
		if (!vis[side[cur][i]])dfs(side[cur][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, e;
	cin >> n >> e;
	memset(vis, 0, sizeof(vis));
	int a, b;
	for (size_t i = 0; i < e; i++)
	{
		cin >> a >> b;
		side[a].push_back(b);
	}
	for (size_t i = 0; i < n; i++) 
		sort(side[i].begin(), side[i].end());
	for (size_t i = 0; i < n; i++)
		if (!vis[i]) dfs(i);
}
