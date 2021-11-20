#include <bits/stdc++.h>
using namespace std;
int vis[22222];
vector<int>graph[22222];

void dfs(int x) {
	cout << x << " ";
	vis[x] = 1;
	sort(graph[x].begin(), graph[x].end());
	int t;
	for (auto t : graph[x]) {
		if (vis[t] == 0)
			dfs(t);
	}
}

int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int p, q;
		cin >> p >> q;
		graph[p].push_back(q);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			dfs(i);
	}
	return 0;
}