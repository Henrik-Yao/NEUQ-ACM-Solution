#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<set>
#include<vector>
#include<sstream>
using namespace std;
const int maxv = 100 + 10;

int pre_order[maxv];
vector<vector<int>>tree(1001);
int n;

bool read_list(int *a) {
	string line;
	if (!getline(cin, line))return false;
	stringstream ss(line);
	n = 0;
	int temp;
	while (ss >> temp)a[n++] = temp;
	return n > 0;
}

int build(int R) {
	static int L = 0;
	if (L > R)return 0;
	int root = pre_order[L];
	if (root == 0)return 0;

	while (pre_order[++L]) {
		tree[root].emplace_back(pre_order[L]);
		build(R);
	}
	return root;
}

int common_root, x, y; bool flag = 0;
int walktree(int root, int sig) {
	if (root == 0)return 0;
	for (auto c : tree[root]) {
		if (c == x || c == y)sig++;
		sig += walktree(c, 0);
		if (flag)return 0;
		if (sig == 2) {
			common_root = root;
			flag = 1;
		}
	}
	return sig;
}

int main() {
	int z;
	cin >> z;
	while (z--) {
		getchar();
		flag = 0;
		memset(pre_order, 0, sizeof(pre_order));
		tree.reserve(10);
		read_list(pre_order);
		build(n - 1);
		cin >> x >> y;
		common_root = pre_order[0];
		walktree(pre_order[0], 0);
		cout << common_root << endl;
	}
}