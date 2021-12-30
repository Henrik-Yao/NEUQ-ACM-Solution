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
  for (int i = 1; i <= n; ++i) a[i] = read();
  int x = read(), l = 1, r = n, mid = 1, cnt = 0;
  while (l <= r) {
    mid = (l + r) >> 1;
    ++cnt;
    if (a[mid] == x)
      break;
    if (a[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  if (a[mid] != x)
		printf("-1\n%d\n", cnt);
  else
		printf("%d\n%d\n", mid - 1, cnt);
  return 0;
}
