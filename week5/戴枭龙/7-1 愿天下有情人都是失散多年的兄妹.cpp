#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
int vis[maxn];
int n, k, lover1, lover2, flag;
int id, dad[maxn], mom[maxn];
char gender[maxn];

void dfs(int x, int t) {
	if (t > 5 || x == -1 || flag || x == 0)
		return ;
	if (vis[x])
		flag = 1;
	vis[x] = 1;
	dfs(dad[x], t + 1);
	dfs(mom[x], t + 1);
	return;
}

int main() {
	cin >> n;
	while (n--) {
		cin >> id >> gender[id] >> dad[id] >> mom[id];
		gender[dad[id]]='M';
		gender[mom[id]]='F';
	}
	cin >> k;
	while (k--) {
		cin >> lover1 >> lover2;
		if (gender[lover1] == gender[lover2]) {
			cout << "Never Mind" << endl;
			continue;
		}
		flag = 0;
		memset(vis, 0, sizeof vis);
		dfs(lover1, 1);
		dfs(lover2, 1);
		if (flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}