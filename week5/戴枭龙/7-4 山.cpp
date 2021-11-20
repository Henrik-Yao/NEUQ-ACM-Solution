#include <iostream>
using namespace std;
const int maxn = 2021;
int a[maxn][ maxn];
int n, m, cnt = 0;
int fa[maxn * maxn], top[maxn * maxn], vis[maxn*maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
	return;
}

bool check(int x, int y, int x0, int y0) {
	if (a[x][y] && a[x0][y0])
		return 1;
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		fa[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check(i - 1, j, i, j)) {
				merge((i - 2)*m + j, (i - 1)*m + j);
			}
			if (check(i + 1, j, i, j)) {
				merge(i * m + j, (i - 1)*m + j);
			}
			if (check(i, j - 1, i, j)) {
				merge((i - 1)*m + j - 1, (i - 1)*m + j);
			}

			if (check(i, j + 1, i, j)) {
				merge((i - 1)*m + j + 1, (i - 1)*m + j);
			}
		}
	}
	for (int i = 1; i <= n * m; i++)
		if (a[(i - 1) / m + 1][i - (i - 1) / m * m])
			top[find(i)]++;
	for (int i = 1; i <= n * m; i++)
		if (top[find(i)] && !vis[find(i)]) {
			cnt++;
			vis[find(i)] = 1;
		}
	cout << cnt;
	return 0;
}
