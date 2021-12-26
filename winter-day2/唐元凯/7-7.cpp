#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

const int maxv = 1000 + 5;

int pre_order[15], in_order[15], lch[maxv], rch[maxv];
vector<int>ans;

int build(int L1, int R1, int L2, int R2) {
	if (L2 > R2)return 0;
	int root = pre_order[L1];
	int p = L2;
	while (in_order[p] != root)p++;
	int cnt = p - L2;
	lch[root] = build(L1 + 1, L1+cnt, L2, p - 1);
	rch[root] = build(L1+ cnt + 1, R1, p + 1, R2);
	return root;
}

bool bfs(int root) {
	queue<int>q;
	ans.clear();
	q.push(root);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (!u)return false;
		ans.emplace_back(u);
		if (lch[u])q.push(lch[u]);
		if (rch[u])q.push(rch[u]);
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (size_t i = 0; i < n; i++) cin >> pre_order[i];
	for (size_t i = 0; i < n; i++) cin >> in_order[i];
	build(0, n - 1, 0, n - 1);
	bfs(pre_order[0]);
	for (auto c : ans) {
		cout << c << " ";
	}
}