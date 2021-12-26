#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

const int maxv = 1000 + 5;
int pre_order[maxv], in_order[maxv], lch[maxv], rch[maxv];
int n;

int build(int L1, int R1, int L2, int R2) {
	if (L2 > R2)return 0;
	int root = pre_order[L1];
	int p = L2;
	while (in_order[p] != root)p++;
	int cnt = p - L2;
	lch[root] = build(L1 + 1, L1 + cnt, L2, p - 1);
	rch[root] = build(L1 + cnt + 1, R1, p + 1, R2);
	return root;
}

void walktree(int root, vector<int> &ans) {
	if (lch[root])walktree(lch[root], ans);
	if (rch[root]) walktree(rch[root], ans);
	ans.emplace_back(root);
	return;
}

int main() {
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> pre_order[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> in_order[i];
	}
	build(0, n - 1, 0, n - 1);
	vector<int>ans;
	walktree(pre_order[0],ans);
	for (auto c : ans) {
		cout << c << " ";
	}
}