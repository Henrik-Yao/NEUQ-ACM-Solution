#include<iostream>
#include<algorithm>
using namespace std;
struct Edge
{
	int from;
	int to;
	int val;
}edge[51];
int parent[51];
int find(int x) {
	int i = x;
	if (parent[i] == i)
		return i;
	else
		return parent[i] = find(parent[i]);
}
bool cmp(Edge a, Edge b) {
	return a.val < b.val;
}
void merge(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a != b)
		parent[a] = b;
}

int main()
{
	int n, v, e;
	while (cin >> n >> v >> e)
    {
		int cnt = 0, ans = 0, num = 0;
		for (int i = 0; i < n; i++)//初始化parent
			parent[i] = i;
		for (int i = 0; i < e; i++)
			cin >> edge[i].from >> edge[i].to >> edge[i].val;
		sort(edge, edge + e, cmp);
		for (int i = 0; i < e; i++) {
			int a = find(edge[i].from);
			int b = find(edge[i].to);
			if (a == b)
				continue;
			else {
				if ((edge[i].from == v || edge[i].to == v) && cnt < 2)//对v的道路需要看cnt特判
                {
					merge(edge[i].from, edge[i].to);
					ans = ans + edge[i].val;
					cnt++;
					num++;
				}
				else if (edge[i].from != v && edge[i].to != v)//普通道路不需要统计到cnt中
				{
					merge(edge[i].from, edge[i].to);
					num++;
					ans = ans + edge[i].val;
				}
				if (num == n - 1)
					break;
			}

		}
		if (num == n - 1 && cnt <= 2)
			cout << ans << endl;
		else
			cout << -1 << endl;

	}
	return 0;
}
