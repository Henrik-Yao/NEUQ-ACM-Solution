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

int n, a[55];

int main() {
	n = read();
  for (int i = 1; i <= n; ++i)
		a[read()]++;
  for (int i = 0; i <= 50; ++i)
		a[i] ? printf("%d:%d\n", i, a[i]) : printf("");
  return 0;
}
