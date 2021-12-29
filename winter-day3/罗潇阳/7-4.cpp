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

const int N = 101;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, a[N][N];

void dfs(int x, int y) {
  a[x][y] = 0;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 1 || nx > n || ny < 1 || ny > m)
      continue;
    if (!a[nx][ny])
      continue;
    dfs(nx, ny);
  }
}

int main() {
	n = read(), m = read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
			a[i][j] = read();
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j]) {
        dfs(i, j);
        ++ans;
      }
  cout << ans << "\n";
  return 0;
}
