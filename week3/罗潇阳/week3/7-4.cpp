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

const int N = 1e3 + 100;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, cnt;
char s[N][N];
int res[N][N], v[N][N];
vector<pair<int, int>>G;

void dfs(int x, int y);

int main() {
#ifndef ONLINE_JUDGE 
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
#endif
	n = read(), m = read();
	rep(i, 1, n) scanf("%s", s[i] + 1);
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (v[i][j]) continue;
			dfs(i, j);
			for (auto x: G) 
				res[x.first][x.second] = cnt;
			G.clear();
			cnt = 0;
		}
	}
	while (m--) 
		printf("%d\n", res[read()][read()]);

	return 0;
}

void dfs(int x, int y) {
    v[x][y] = 1; 
		++cnt;
    G.push_back(make_pair(x, y));
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n || v[nx][ny]) 
					continue;
        if (s[nx][ny] == s[x][y]) continue;
        dfs(nx, ny);
    }
}

