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

const int N = 51;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int n, m, k, l;
int type[N][N], mark[N][N];

void dfs(int x, int y);

int main() {
#ifndef ONLINE_JUDGE 
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
#endif
	n = read(), m = read(), k = read(), l = read();
	rep(i, 1, k) {
		int x = read() + 1, y = read() + 1;
		type[x][y] = 1;
	}
	memset(mark, -1, sizeof(mark));
	while (l--) {
		int x = read() + 1, y = read() + 1;
		if (mark[x][y] != -1) continue;
		if (type[x][y]) {
			puts("You lose");
			return 0;
		}
		dfs(x, y);
		rep(i, 1, n) {
			rep(j, 1, m) printf("%d ", mark[i][j]);
			puts("");
		}
		bool ok = true;
		rep(i, 1, n) {
			rep(j, 1, m) {
				if (mark[i][j] == -1 && !type[i][j]) {
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}
		if (ok) { 
			puts("You win"); 
			return 0;
		}
		puts("");
	}
	return 0;
}

void dfs(int x, int y) {
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (type[nx][ny]) ++res;
    }
    mark[x][y] = res;
    if (res) return;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if (type[nx][ny] || mark[nx][ny] != -1) continue;
        dfs(nx, ny);
    }
}

