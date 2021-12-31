#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}

int N, a[50], b[50];

void dfs(int l1, int r1, int l2, int r2) {
	if (l1 > r1) return;
	if (l1 == r1) return (void)(printf("%d ", a[l1]));
	int pos = l2;
	for (int i = l2; i <= r2; ++i) if (b[i] == a[r1]) { pos = i; break; }
	printf("%d ", a[r1]);
	dfs(l1, l1 + (pos - l2) - 1, l2, pos - 1);
	dfs(l1 + (pos - l2), r1 - 1, pos + 1, r2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read();
	for (int i = 1; i <= N; ++i) a[i] = read();
	for (int i = 1; i <= N; ++i) b[i] = read();
	dfs(1, N, 1, N);
	return 0;
}
