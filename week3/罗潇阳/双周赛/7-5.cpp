#include <bits/stdc++.h>
using namespace std;

typedef long long var;
typedef long double let;
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define repl(i, t) for (int i = fi[t]; i; i = ne[i])

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

void solve();

int main() {
	// freopen("main.in", "r", stdin);
	// freopen("main.out", "w", stdout);
	int T = read();
	while (T--) solve();
	return 0;
}

int v1[101], v2[101], res[1000];

void solve() {
	int n = read();
	rep(i, 1, n) v1[i] = read();
	int m = read();
	rep(i, 1, m) v2[i] = read();
	int c1 = 1, c2 = 1, cnt = 0;
	rep(i, 1, n + m) {
		if (c2 > m || (c1 <= n && v1[c1] < v2[c2])) res[++cnt] = v1[c1++];
		else res[++cnt] = v2[c2++];
	}
	rep(i, 1, n + m - 1) printf("%d ", res[i]);
	printf("%d\n", res[n + m]);
}
