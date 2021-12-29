#include<bits/stdc++.h>
using namespace std;

struct stu {
	int u;
	int v;
	int c;
};
vector<stu> v;
int fa[10001];

bool cmp(stu x, stu y) {
	return x.c < y.c;
}
int find(int x) {
	if (fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}

void lh(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if (f1 != f2)
		fa[f1] = f2;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		stu x;
		cin >> x.u >> x.v >> x.c;
		v.push_back(x);
	}
	int x = 0, max = 0;
	for (int i = 0; i < n; i++)
		fa[i] = i;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < m; i++) {
		if (find(v[i].u) != find(v[i].v)) {
			lh(v[i].u, v[i].v);
			if (max < v[i].c)
				max = v[i].c;
			x++;
		}
	}
	cout << x << " " << max;
	return 0;
}