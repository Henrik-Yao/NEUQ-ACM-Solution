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

var f[45];

int main() {
  f[1] = f[2] = 1;
  for (int i = 3; i <= 40; ++i)
    f[i] = f[i - 1] + f[i - 2];

  int T = read();
  f[1] = 0;
  while (T--)  printf("%lld\n", f[read()]);
  return 0;
}
