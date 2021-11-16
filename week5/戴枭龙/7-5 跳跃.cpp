#include <bits/stdc++.h>
using namespace std;
int n, m[55555], vis[55555], start, flag = 0;

void dfs(int x) {
	vis[x] = 1;
	if (m[x] == 0) {
		flag = 1;
		return ;
	}
	if (x >= 0 && x < n && !vis[x + m[x]])
		dfs(x + m[x]);
	if (x >= 0 && x < n && !vis[x - m[x]])
		dfs(x - m[x]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	cin >> start;
	dfs(start);
	if (flag)
		cout << "True";
	else
		cout << "False";
	return 0;
}