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

const int N = 1e5 + 1;

int n, m;
int top, fi[N], ne[N], to[N];
bool mark[N];

void add(int u, int v);

int main() {
	n = read(), m = read();
	rep(i, 1, m) add(read(), read());
	int T = read();
	while (T--) {
		int k = read();
		memset(mark, false, sizeof(mark));
		rep(i, 1, k) mark[read()] = true;
		bool ok = true;
		rep(i, 1, n) {
			if (mark[i]) continue;
			repl(j, i) {
				if (!mark[to[j]]) {
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}

void add(int u, int v) {
	ne[++top] = fi[u], fi[u] = top, to[top] = v;
	ne[++top] = fi[v], fi[v] = top, to[top] = u;
}
