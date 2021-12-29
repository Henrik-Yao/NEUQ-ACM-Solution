#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

const int maxn = 2e5 + 5;

int N, M;
struct node { int v, w; };
inline bool operator <(node a, node b) { return a.v < b.v; }
vector <node> u[maxn];

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read(), M = read();
	for (int i = 1; i <= M; ++i) {
		int x = read(), y = read(), z = read();
		u[x].push_back({ y,z });
	}
	M = read();
	for (int i = 1; i <= M; ++i) {
		int x = read(), y = read();
		for (auto j = u[x].begin(); j != u[x].end(); ) {
			if (j->v == y) {
				u[x].erase(j);
				break;
			}
			else ++j;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (u[i].size() == 0) continue;
		sort(u[i].begin(), u[i].end());
		printf("%d:", i);
		for (int j = 0; j < u[i].size(); ++j)
			printf("(%d,%d,%d)", i, u[i][j].v, u[i][j].w);
		puts("");
	}
	return 0;
}
