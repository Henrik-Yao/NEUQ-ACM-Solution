#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}
const int INF = 0x3f3f3f3f;
int N, M, a[105][105], f[105][105];

void display(int x, int y) {
	if (x == y) return;
	if (a[x][y] == f[x][y]) return void(printf("%d->", x));
	for (int k = 0; k < N; ++k)
		if (k !=x && k != y && f[x][y] == f[x][k] + f[k][y]) {
			display(x, k), display(k, y);
			return;
		}
}

void Calc() {
	int U = read(), V = read();
	if (U == V) return void(printf("%d->%d:0\n", U, U));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) f[i][j] = a[i][j];
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (f[i][j] > f[i][k] + f[k][j])
					f[i][j] = f[i][k] + f[k][j];
	//for (int i = 0; i < N; ++i, puts(""))
	//	for (int j = 0; j < N; ++j)
	//		printf("%d ", f[i][j] == INF ? -1 : f[i][j]);
	//puts("");
	if (f[U][V] < INF) display(U, V), printf("%d:%d\n", V, f[U][V]);
	else printf("%d->%d:-1\n", U, V);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	memset(a, 0x3f, sizeof a);
	N = read(), M = read();
	for (int i = 0; i < N; ++i) a[i][i] = 0;
	for (int i = 1; i <= M; ++i) {
		int x = read(), y = read();
		a[x][y] = read();
	}
	Calc(), Calc();
	int mx = 0, st = 1, ed = 1;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (f[i][j] > mx && f[i][j] != INF)
				mx = f[i][j], st = i, ed = j;
	display(st, ed), printf("%d:%d\n", ed, f[st][ed]);
	return 0;
}
