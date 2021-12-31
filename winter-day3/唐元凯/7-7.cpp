#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 5;
int u[maxn], v[maxn], c[maxn],p[maxn],r[maxn];
int n, z, m;//n,v,e

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
int Kruskal() {
	int ans = 0;
	for (int i = 0; i < n; i++)p[i] = i;
	for (int i = 0; i < m; i++)r[i] = i;
	sort(r, r + m, [](const int &i, const int &j) {return c[i] < c[j]; });
	int cnt = 0, cnt_2 = 0;
	for (int i = 0; i < m; i++) {
		int e = r[i];
		if (u[e] == z || v[e] == z) {
			int x = find(u[e]); int y = find(v[e]);
			if (cnt_2 < 2 && x != y) {
				ans += c[e];
				p[x] = y;
				++cnt;
				++cnt_2;
			}
		}
		else if (u[e] != z && v[e] != z) {
			int x = find(u[e]); int y = find(v[e]);
			if (x != y) {
				ans += c[e];
				p[x] = y;
				++cnt;
			}
		}
		if (cnt == n - 1)break;
	}
	if (cnt != n - 1)ans = 0;
	return ans;
}

int main() {
	while (cin >> n >> z >> m) {
		memset(u, 0, sizeof(u));
		memset(v, 0, sizeof(v));
		memset(c, 0, sizeof(c));
		memset(p, 0, sizeof(p));
		memset(r, 0, sizeof(r));
		for (int i = 0; i < m; i++) {
			cin >> u[i] >> v[i] >> c[i];
		}
		int ans = Kruskal();
		if (ans)cout << ans << endl;
		else cout << -1 << endl;
	}
}