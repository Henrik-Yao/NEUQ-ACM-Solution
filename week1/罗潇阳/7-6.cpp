#include<bits/stdc++.h>
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

int n, T;

int calc(int t, int f) {
	if (t > T) return f - (t - T);
	return f;
}

int main() {
	n = read(), T = read();
	int res = calc(read(), read());
	rep(i, 2, n) res = max(res, calc(read(), read()));
	printf("%d\n", res);
	return 0;
}
