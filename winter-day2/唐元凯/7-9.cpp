#include<iostream>
using namespace std;

const int maxv = 1000 + 5;
int post_order[maxv], in_order[maxv], lch[maxv], rch[maxv];
int n;

int build(int L1, int R1, int L2, int R2) {
	if (L1 > R1)return 0;
	int root = post_order[R2];
	int p = L1;
	while (in_order[p] != root)p++;
	int cnt = p - L1;
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}

void walktree(int root) {
	cout << root << " ";
	if(lch[root])walktree(lch[root]);
	if(rch[root])walktree(rch[root]);
}

int main() {
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> post_order[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> in_order[i];
	}
	build(0, n - 1, 0, n - 1);
	walktree(post_order[n - 1]);
}