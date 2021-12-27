#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e4 + 5;
int u[maxn], v[maxn], c[maxn],p[maxn],r[maxn];
int n, m;

int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
int Kruskal() {
	int ans = 0;
	for (int i = 0; i < n; i++)p[i] = i;
	for (int i = 0; i < m; i++)r[i] = i;
	sort(r, r + m, [](const int &i, const int &j) {return c[i] < c[j]; });
	for (int i = 0; i < m; i++) {
		int e = r[i];
		int x = find(u[e]); int y = find(v[e]);
		if (x != y) {
			ans = max(ans, c[e]);
			p[x] = y;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> u[i] >> v[i] >> c[i];
	cout<<n-1<<" "<<Kruskal();
}