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
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
      cout << a[i] << (i == n ? '\n' : ' ');
    int m = read();
    while (m--) {
      int x = read();
      int y = lower_bound(a + 1, a + 1 + n, x) - a;
      if (a[y] == x)
        cout << y;
      else
        cout << "0";
      if (m)
        cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
