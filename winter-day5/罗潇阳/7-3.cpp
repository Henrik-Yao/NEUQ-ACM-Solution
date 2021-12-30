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

const int N = 500010;
int n, a[N];

int main() {
	n = read();
  for (int i = 1; i <= 2 * n; ++i) a[i] = read();
  nth_element(a + 1, a + n, a + 1 + 2 * n);
	printf("%d\n", a[n]);
  return 0;
}
