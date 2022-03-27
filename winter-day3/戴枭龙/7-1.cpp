#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[20005];

struct Node {
	int from;
	int to;
	int value;
} node[20005];

bool cmp(Node a, Node b) {
	if (a.from != b.from)
		return (a.from < b.from);
	else
		return (a.to < b.to);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> node[i].from >> node[i].to >> node[i].value;
		cnt[node[i].from]++;
	}
	sort(node + 1, node + m + 1, cmp);
	int tmp = 1;
	for (int i = 0; i < n; i++) {
		if (cnt[i] == 0)
			continue;
		cout << node[tmp].from << ":";
		for (int j = 1; j <= cnt[i]; j++) {
			printf("(%d,%d,%d)", node[tmp].from, node[tmp].to, node[tmp].value);
			tmp++;
		}
		cout << endl;
	}
}