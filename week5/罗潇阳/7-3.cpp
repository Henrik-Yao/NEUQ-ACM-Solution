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

int v[20010];
vector<int> G[20010], ans;

void dfs(int x);

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
  }
  for (int i = 0; i < n; ++i)
    sort(G[i].begin(), G[i].end());
  for (int i = 0; i < n; ++i)
    if (!v[i])
      dfs(i);
  for (int i = 0; i < ans.size(); ++i)
    printf("%d ", ans[i]);
  return 0;
}

void dfs(int x) {
  v[x] = 1;
  ans.push_back(x);
  for (auto y : G[x]) {
    if (v[y])
      continue;
    dfs(y);
  }
}
