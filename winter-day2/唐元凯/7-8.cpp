#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

const int maxv = 10000 + 5;
int bfans[maxv], lch[maxv], rch[maxv];
int num;

bool build(int root, int floor) {
	int n = 1;
	queue<int>q;
	q.push(root);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (n < num)lch[u] = bfans[n++];
		else break;
		if (n < num)rch[u] = bfans[n++];
		else break;
		q.push(lch[u]);
		q.push(rch[u]);
	}
	return true;
}

int height = 1, bestans = 1;
void in_ans_height(int root, vector<int> &ans)
{
	if (lch[root]) {
		++height;
		if (height > bestans)bestans = height;
		in_ans_height(lch[root], ans);
	}
	ans.emplace_back(root);
	if (rch[root]) {
		++height;
		if (height > bestans)bestans = height;
		in_ans_height(rch[root], ans);
	}
	--height;
	return;
}

int main() {
	int k;
	cin >> k;
	vector<int>ans;
	while (k--) {
		cin >> num;
		memset(bfans, 0, sizeof(bfans));
		memset(lch, 0, sizeof(lch));
		memset(rch, 0, sizeof(rch));
		for (size_t i = 0; i < num; i++) cin >> bfans[i];
		build(bfans[0], 1);
		ans.clear();
		height = 1, bestans = 1;
		in_ans_height(bfans[0], ans);
		for (auto &c : ans) {
			cout << c;
			if (&c != &ans[ans.size() - 1])cout << " ";
		}
		cout << endl;
		cout << bestans << endl;
	}
}