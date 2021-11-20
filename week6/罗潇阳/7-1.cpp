#include <bits/stdc++.h>
using namespace std;

typedef long long var;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define repl(i, t) for (int i = fi[t]; i; i = ne[i])

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

const int MAXN = 1000010;
const ull Base = 107;

int n;
ull h[MAXN], p[MAXN];
char s[MAXN], t[MAXN];

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    h[i] = h[i - 1] * Base + (ull)s[i];
  p[0] = 1;
  for (int i = 1; i <= n; ++i)
    p[i] = p[i - 1] * Base;
  scanf("%s", t + 1);
  int m = strlen(t + 1);
  ull ht = 0;
  int res = 0;
  for (int i = 1; i <= m; ++i)
    ht = ht * Base + (ull)t[i];
  for (int i = 1; i + m - 1 <= n; ++i) {
    ll hs = h[i + m - 1] - h[i - 1] * p[m];
    if (hs == ht)
      ++res;
  }
  printf("%d\n", res);
  return 0;
}
