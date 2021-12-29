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

int n, m;
vector<pair<int, int>> G[N];

int main() {
	n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
    G[u].push_back(make_pair(v, w));
  }
  for (int i = 0; i < n; ++i)
    sort(G[i].begin(), G[i].end());
  for (int i = 0; i < n; ++i) {
    if (!G[i].size())
      continue;
    cout << i << ":";
    for (int j = 0; j < G[i].size(); ++j) {
      cout << "(" << i << ",";
      cout << G[i][j].first << "," << G[i][j].second << ")";
    }
    cout << "\n";
  }
  return 0;
}
