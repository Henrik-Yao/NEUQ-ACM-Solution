#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

const int xx[4] = { 0,0,1,-1 };
const int yy[4] = { 1,-1,0,0 };
int N, M, Ans, a[105][105];
vector <string> v;

void dfs(int x, int y) {
	a[x][y] = 0;
	for (int f = 0; f < 4; ++f) {
		int u = x + xx[f];
		int v = y + yy[f];
		if (u > 0 && u <= N && v > 0 && v <= M && a[u][v])
			dfs(u, v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read(), M = read();
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			a[i][j] = read();
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (a[i][j]) ++Ans, dfs(i, j);
	printf("%d\n", Ans);
	return 0;
}
