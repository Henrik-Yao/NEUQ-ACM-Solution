#include <bits/stdc++.h>
using namespace std;
int n, m, k, cnt[20005], ccnt[20005];

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
	for (int i = 0; i < m; i++) {
		cin >> node[i].from >> node[i].to >> node[i].value;
		cnt[node[i].from]++;
	}
	cin >> k;
	for (int i = m; i < m + k; i++) {
		cin >> node[i].from >> node[i].to;
		node[i].value = -666666;
		cnt[node[i].from]++;
	}
	sort(node, node + m + k, cmp);
	for (int i = 0; i < m + k; i++) {
		if ((node[i].from == node[i - 1].from && node[i].to == node[i - 1].to) ||
		        (node[i].from == node[i + 1].from && node[i].to == node[i + 1].to)) {
			node[i].value = -666666;
			ccnt[node[i].from] = ccnt[node[i].from] + 1;
		}
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i] == ccnt[i]) {
			temp = temp + ccnt[i];
			continue;
		}
		cout << node[temp].from << ":";
		for (int j = 0; j < cnt[i]; j++) {
			if (node[temp].value == -666666) {
				temp++;
				continue;
			}
			printf("(%d,%d,%d)", node[temp].from, node[temp].to, node[temp].value);
			temp++;
		}
		cout << endl;
	}
}