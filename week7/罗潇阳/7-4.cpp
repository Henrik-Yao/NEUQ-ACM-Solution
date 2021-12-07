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


int f[1010], a[1010];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &a[i]);
    int ans = 1;
    a[0] = -1;
    for (int i = 1; i <= n; ++i) {
      f[i] = 0;
      for (int j = 0; j < i; ++j)
        if (a[i] > a[j])
          f[i] = max(f[i], f[j] + 1);
      ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    if (T)
      puts("");
  }
  return 0;
}
