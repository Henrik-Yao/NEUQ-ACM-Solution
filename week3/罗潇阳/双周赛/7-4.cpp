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

typedef unsigned long long ull;

int n;
ull f[65];

ull getf(int n);
ull getg(int n);

int main() {
#ifndef ONLINE_JUDGE 
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
#endif
	f[1] = 1;

	while(cin >> n) {
		cout << getf(n) << endl;
	}
}

ull getg(int n) {
	return (1ull << n) - 1ull;
}

ull getf(int n) {
	if (f[n]) return f[n];
	f[n]--;
	rep(a, 1, n - 1) {
		int b = n - 1 - a;
		f[n] = min(f[n], getf(a) + getg(b) + 1ull + getg(b) + getf(a));
	}
	return f[n];
}
