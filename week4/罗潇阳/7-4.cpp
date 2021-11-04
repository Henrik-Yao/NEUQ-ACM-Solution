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

var qpow(var a, var b, var p);

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
		var a = read(), b = read(), p = read();
    printf("%lld\n", qpow(a, b, p));
  }
  return 0;
}

var qpow(var a, var b, var p) {
  var ans = 1 % p;
	while (b) {
    if (b & 1)
			(ans *= a) %= p;
		(a *= a) %= p;
		b >>= 1;
  }
  return ans;
}
