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

int n, a[10010], f[10010], ans;

int main() {
#ifndef ONLINE_JUDGE 
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
#endif
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		f[i] = max(f[i - 1] + a[i], f[i]);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}

/*
CAR:
	make Compile
	make Run

Compile:
	g++ -o main main.cpp -g

Run:
	./main
 */
