#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m;
int sum = 0, amax = 0;
int v[maxn] = {};
struct node
{
	int x, y, w;

}t[maxn];
bool cmp(node a, node b)
{
	return a.w < b.w;
}
int find(int a)
{
	if (v[a] == a) return a;
	return v[a]=find(v[a]);
}
void uni(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b) v[a] = v[b];
}
void solve()
{
	for (int i = 1; i <=m; i++)
	{
		int x1 = t[i].x, y1 = t[i].y;
		if (find(x1) != find(y1))
		{
			uni(x1, y1);
			sum++;
			amax = t[i].w;
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <=m; i++)//初始化
	{
		v[i] = i;
	}
	for (int i = 1; i <= m; i++)//m行
	{
		scanf("%d%d%d", &t[i].x, &t[i].y, &t[i].w);
	}
	sort(t + 1, t + 1 + m, cmp);//从小到大排序
	solve();
	cout << sum << " " << amax;
	return 0;
}