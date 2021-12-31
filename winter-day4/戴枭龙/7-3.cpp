#include <bits/stdc++.h>
using namespace std;
int ma[1001][1001], n;
int dis[1001], f[1001], Distance = 0;
bool vis[1001];

void print_way(int from, int to) {
	if (from == to) {
		cout << from;
		return ;
	}
	Distance = Distance + ma[to][f[to]];
	print_way(from, f[to]);
	cout << "-->" << to;
}

void find_way(int from) {
	dis[from] = 0;
	for (int i = 0; i < n; i++)
		f[i] = i;
	for (int i = 0; i < n; i++) {
		int minx = 0x3f, p = -1;
		for (int j = 0; j < n; j++) {
			if (!vis[j]  && dis[j] < minx) {
				minx = dis[j];
				p = j;
			}
		}
		if (p == -1)
			return ;
		vis[p] = 1;
		for (int k = 0; k < n; k++) {
			if (vis[k] == 0 && ma[p][k] < dis[1000] && dis[p] + ma[p][k] < dis[k]) {
				dis[k] = dis[p] + ma[p][k];
				f[k] = p;
			}
		}
	}
}

int main() {
	int e, a, b, c;
	memset(ma, 0x3f, sizeof(ma));
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	cin >> n >> e;
	for (int i = 0; i < e / 2; i++) {
		cin >> a >> b >> c;
		ma[a][b] = c;
		ma[b][a] = c;
	}
	int from, to;
	cin >> from >> to;
	if (from == to) {
		cout << from << "-->" << to << ":0";
		return 0;
	}
	find_way(from);
	print_way(from, to);
	cout << ":" << Distance;
	return 0;
}