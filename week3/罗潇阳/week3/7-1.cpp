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

const int N = 1e4 + 1;

int m, n, k;
int top, fi[N], ne[N], to[N];
int safe[N], mark[N];

void add(int u, int v) {
	ne[++top] = fi[u], fi[u] = top, to[top] = v;
	ne[++top] = fi[v], fi[v] = top, to[top] = u;
}

void dfs(int x) {
	mark[x] = true;
	repl(i, x) {
		if (mark[to[i]] || !safe[to[i]]) continue;
		dfs(to[i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE 
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
#endif
	m = read(), n = read(), k = read();
	rep(i, 1, n) safe[read()] = 1;
	rep(i, 1, k) add(read(), read());
	int s = read(), t = read();
	if (!safe[t]) {
		printf("The city %d is not safe!\n", t); 
		return 0;
	}

	dfs(s);

	if (mark[t]) 
		printf("The city %d can arrive safely!\n", t);
	else 
		printf("The city %d can not arrive safely!\n", t);
	return 0;
}
