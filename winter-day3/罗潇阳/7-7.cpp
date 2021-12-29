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

const int N = 100010;

int n, m, fa[N];
struct Edge {
  var u, v, w;
  friend bool operator < (const Edge &a, const Edge &b) { 
		return a.w < b.w; 
	}
} e[N];

inline int get(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = get(fa[x]);
}

int main() {
  int num;
  while (cin >> n >> num >> m) {
    ++num;
    for (int i = 1; i <= m; ++i)
			e[i] = (Edge){read() + 1, read() + 1, read()};
    for (int i = 1; i <= n; ++i)
      fa[i] = i;
    sort(e + 1, e + 1 + m);
    int cnt = 0;
    var sum = 0;
    int tim = 0;
    for (int i = 1; i <= m; ++i) {
      int u = e[i].u, v = e[i].v, w = e[i].w;
      if (get(u) == get(v))
        continue;
      if (u == num || v == num) {
        if (tim >= 2)
          continue;
        ++tim;
      }
      sum += w;
      ++cnt;
      fa[get(u)] = get(v);
    }
    if (cnt == n - 1)
      cout << sum << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
