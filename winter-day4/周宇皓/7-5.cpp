#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}
const int INF = 65535;
const int xx[4] = { 0,1,0,-1 };
const int yy[4] = { 1,0,-1,0 };
bool vis[505][505];
int N, M, a[505][505], dis[505][505], lst[505][505];
int sX, sY, eX, eY;
struct Node { int dis, x, y; };
inline bool operator <(Node a, Node b) { return a.dis > b.dis; }
priority_queue <Node> Q;

void dfs(int x, int y) {
	if (x == sX && y == sY) return void(printf("(%d %d)", x, y));
	printf("(%d %d)", x, y);
	dfs(x - xx[lst[x][y]], y - yy[lst[x][y]]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read(), M = read();
	sX = read(), sY = read();
	eX = read(), eY = read();
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			a[i][j] = read(), dis[i][j] = INF;
	dis[sX][sY] = a[sX][sY];
	Q.push({ dis[sX][sY], sX, sY });
	while (!Q.empty()) {
		Node tp = Q.top(); Q.pop();
		if (vis[tp.x][tp.y]) continue;
		vis[tp.x][tp.y] = 1;
		if (tp.x == eX && tp.y == eY) break;
		for (int f = 0; f < 4; ++f) {
			int x = tp.x + xx[f];
			int y = tp.y + yy[f];
			if (x < 0 || y < 0 || x == N || y == M) continue;
			if (a[x][y] == -1) continue;
			if (dis[x][y] > dis[tp.x][tp.y] + a[x][y]) {
				dis[x][y] = dis[tp.x][tp.y] + a[x][y];
				lst[x][y] = f;
				Q.push({ dis[x][y],x,y });
			}
		}
	}
	dfs(eX, eY);
	return 0;
}

