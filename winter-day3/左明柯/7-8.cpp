#include<iostream>
#include<algorithm>
using namespace std;
struct Edge {
	int from;
	int to;
	int val;
}edge[51];
int parent[51];
int find(int x) {
	int r = x;
	if (parent[r] == r)
		return r;
	else
		return parent[r] = find(parent[r]);
}
bool paixu(Edge a, Edge b) {
	return a.val < b.val;
}
void merge(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a != b)
		parent[a] = b;
}

int main() {
	int n, v, e;
	while (cin >> n >> v >> e) {
		int count = 0, ans = 0, num = 0;
		for (int i = 0; i < n; i++)
			parent[i] = i;
		for (int i = 0; i < e; i++)
			cin >> edge[i].from >> edge[i].to >> edge[i].val;
		sort(edge, edge + e, paixu);
		for (int i = 0; i < e; i++) {
			int a = find(edge[i].from);
			int b = find(edge[i].to);
			if (a == b)
				continue;
			else {
				if ((edge[i].from == v || edge[i].to == v) && count < 2) {
					merge(edge[i].from, edge[i].to);
					ans = ans + edge[i].val;
					count++;
					num++;
				}
				else if (edge[i].from != v && edge[i].to != v) {
					merge(edge[i].from, edge[i].to);
					num++;
					ans = ans + edge[i].val;
				}
				if (num == n - 1)
					break;

			}
			
		}
		if (num == n - 1 && count <= 2)
			cout << ans << endl;
		else
			cout << -1 << endl;

	}

}
