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

bool v[10000010];

int main() {
	int n = read(), ans = 0;
  for (int i = 2; i <= n; ++i) {
    if (v[i]) continue;
    ++ans;
    for (int j = i; j <= n; j += i)
      v[j] = 1;
  }
  printf("%d\n", ans);
  return 0;
}
