#include <bits/stdc++.h>
using namespace std;
int f[1505];

struct Node {
	int from;
	int to;
	int value;
};

bool cmp(Node node1, Node node2) {
	return (node1.value < node2.value);
}

int find(int x) {
	if (f[x] == x)
		return x;
	else
		return f[x] = find(f[x]);
}

void merge(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a != b)
		f[a] = b;
}


int main() {
	int n, e;
	while (cin >> n >> e) {
		Node node[1505];
		int flag[1505] = {0};
		for (int i = 0; i < n; i++)
			f[i] = i;
		for (int i = 0; i < e; i++) {
			cin >> node[i].from >> node[i].to >> node[i].value;
			merge(node[i].from, node[i].to);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (f[i] == i)
				cnt++;
		if (cnt != 1) {
			cout << "There is no minimum spanning tree.\n";
			continue;
		}
		sort(node, node + e, cmp);
		cnt = 0;
		for (int i = 0; i < e; i++) {
			if (flag[node[i].from] == 1 && flag[node[i].to] == 1)
				continue;
			else {
				flag[node[i].from] = 1;
				flag[node[i].to] = 1;
				cnt = cnt + node[i].value;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}