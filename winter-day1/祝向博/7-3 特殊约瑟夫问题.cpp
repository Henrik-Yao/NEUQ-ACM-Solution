#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

int N, M, K, cnt, pos, f = -1, now;
bool vis[1005];

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif // !ONLINE_JUDGE
	N = read(), M = read(), K = read(), pos = 1, now = 0;
	while (cnt < N) {
		if (!vis[pos]) ++now;
		if (f == -1 && now == M || f == 1 && now == K) {
			vis[pos] = 1;
			now = 1;
			f = -f;
			++cnt;
			printf("%d ", pos);
			//puts("");
		}
		pos += f;
		if (pos == N + 1) pos = 1;
		if (pos == 0) pos = N;
	}
	return 0;
}
