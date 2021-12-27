#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

struct Tnode {
	bool isLeaf = 0;
	int w, ls = -1, rs = -1;
	long long sum = 0;
} a[maxn];

bool vis[maxn];
int Sum[maxn], N = 1, Max, Ans = 1;

void buildTree(int x, int dep) {
	cin >> a[x].w;
	if (a[x].w == 0) return;
	if (dep > Max) Max = dep;
	a[x].ls = ++N, buildTree(N, dep + 1);
	a[x].rs = ++N, buildTree(N, dep + 1);
	if (a[a[x].ls].w == 0 && a[a[x].rs].w == 0) Sum[dep] += a[x].w, vis[dep] = 1;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	buildTree(1,1);
	Ans = Max;
	for (int i = Max - 1; i; --i) if (vis[i] && Sum[i] > Sum[Ans]) Ans = i;
	printf("%d\n", Ans - 1);
	return 0;
}
