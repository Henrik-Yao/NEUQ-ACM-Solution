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
	int n, v, e;
	while (cin >> n >> v >> e) {
		memset(f, 0, sizeof(f));
		int expense = 0, flag = 2, cnt = 0;
		Node node[100];
		for (int i = 0; i < n; i++)
			f[i] = i;
		for (int i = 0; i < e; i++)
			cin >> node[i].from >> node[i].to >> node[i].value;
		sort(node, node + e, cmp);
		for (int i = 0; i < e; i++) {
			if (find(node[i].from) != find(node[i].to)) {
				if (node[i].from == v || node[i].to == v) {
					if (flag == 0)
						continue;
					else
						flag--;
				}
				merge(node[i].from, node[i].to);
				expense = expense + node[i].value;
			}
		}
		for (int i = 0; i < n; i++)
			if (find(i) == i)
				cnt++;
		if (cnt != 1)
			cout << "-1\n";
		else
			cout << expense << "\n";
	}
	return 0;
}