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

int n, m;
var a[N];

bool Check(var mid);

int main() {
	n = read(), m = read();
  for (int i = 1; i <= n; ++i)
		a[i] = read();
  sort(a + 1, a + 1 + n);
  var l = 1, r = 0x7fffffff, ans;
  while (l <= r) {
    var mid = (l + r) >> 1;
    if (Check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  cout << ans << "\n";
  return 0;
}

bool Check(var mid) {
  int cnt = 1;
  var lst = a[1];
  for (int i = 2; i <= n; ++i)
    if (a[i] - lst >= mid)
      lst = a[i], ++cnt;
  if (cnt >= m)
    return 1;
  return 0;
}
