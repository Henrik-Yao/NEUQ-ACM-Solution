#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char maze[maxn][maxn];
int vis[maxn][maxn];
int Ans[maxn * maxn];
int n, m, sx, sy, ans, cnt;

void search(int x, int y, int t) {
	if (y + 1 <= n && maze[x][y] != maze[x][y + 1] && vis[x][y + 1] == 0) {
		ans++;
		vis[x][y + 1] = cnt;
		search(x, y + 1, t);
	}
	if (x + 1 <= n && maze[x][y] != maze[x + 1][y] && vis[x + 1][y] == 0) {
		ans++;
		vis[x + 1][y] = cnt;
		search(x + 1, y, t);
	}
	if (x - 1 >= 1 && maze[x][y] != maze[x - 1][y] && vis[x - 1][y] == 0) {
		ans++;
		vis[x - 1][y] = cnt;
		search(x - 1, y, t);
	}
	if (y - 1 >= 1 && maze[x][y] != maze[x][y - 1] && vis[x][y - 1] == 0) {
		ans++;
		vis[x][y - 1] = cnt;
		search(x, y - 1, t);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> maze[i][j];
	while (m--) {
		cin >> sx >> sy;
		int idx = vis[sx][sy];
		if (idx == 0) {
			ans = 1;
			vis[sx][sy] = ++cnt;
			search(sx, sy, cnt);
			Ans[cnt] = ans;
			cout << Ans[cnt] << endl;
		} else
			cout << Ans[idx] << endl;
	}
	return 0;
}