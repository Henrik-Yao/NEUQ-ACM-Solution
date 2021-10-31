#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, x, y, cnt;
int num[21][21], print[21][21];

int dx[8][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
bool mine[21][21], vis[21][21];

void dfs(int x, int y) {
	cnt++;
	vis[x][y] = 1;
	if (num[x][y]) {
		print[x][y] = num[x][y];
		return;
	}
	print[x][y] = 0;
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i][0];
		int ty = y + dx[i][1];
		if (!(tx >= 0 && tx < n && ty >= 0 && ty < m) || vis[tx][ty])
			continue;
		dfs(tx, ty);
	}
	return;
}

int main() {
	cin >> n >> m >> k >> l;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		mine[x][y] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			print[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int k = 0; k < 8; k++) {
				int tx = i + dx[k][0];
				int ty = j + dx[k][1];
				if (!(tx >= 0 && tx < n && ty >= 0 && ty < m) )
					continue;
				if (mine[tx][ty])
					sum++;
			}
			num[i][j] = sum;
		}
	}
	for (int i = 1; i <= l; i++) {
		cin >> x >> y;
		if (vis[x][y])
			continue;
		if (mine[x][y]) {
			cout << "You lose" << endl;
			return 0;
		}
		dfs(x, y);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << print[i][j] << " ";
			}
			cout << endl;
		}

		if (cnt == n * m - k) {
			cout << "You win" << endl;

			return 0;
		}
		cout << endl;
	}

	return 0;
}