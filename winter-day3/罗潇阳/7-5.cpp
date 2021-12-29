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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

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
	n = read(), m = read();
  for (int i = 1; i <= m; ++i)
		e[i] = (Edge) { read(), read(), read() };
  for (int i = 1; i <= n; ++i)
    fa[i] = i;
  sort(e + 1, e + 1 + m);
  var sum = 0;
  for (int i = 1; i <= m; ++i) {
    int u = e[i].u, v = e[i].v, w = e[i].w;
    if (get(u) == get(v))
      continue;
    sum = max(sum, (var)w);
    fa[get(u)] = get(v);
  }
  cout << n - 1 << " " << sum << "\n";
  return 0;
}
