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

const int N = 1000010;

int a[N];

int main() {
	int n = read(), x = read();
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + 1 + n);
	printf("%d\n", lower_bound(a + 1, a + 1 + n, x) - a);
	return 0;
}
