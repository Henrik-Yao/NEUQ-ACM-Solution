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
  while (cin >> n >> m) {
    for (int i = 1; i <= m; ++i)
			e[i] = (Edge) {read(), read(), read()};
    for (int i = 1; i <= n; ++i)
      fa[i] = i;
    sort(e + 1, e + 1 + m);
    var sum = 0;
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
      int u = e[i].u, v = e[i].v, w = e[i].w;
      if (get(u) == get(v))
        continue;
      sum += w;
      fa[get(u)] = get(v);
      ++cnt;
    }
    if (cnt == n - 1)
      cout << sum << "\n";
    else
      cout << "There is no minimum spanning tree.\n";
  }
  return 0;
}
