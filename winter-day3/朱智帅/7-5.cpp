#include<iostream>
#include<algorithm>
using namespace std;
int a[400];
struct Edge
{
	int u, v, weight;
};
void Init()
{
	int i;
	for (i = 0; i < 400; i++)
		a[i] = i;
}
int find(int x)
{
	while (x != a[x])
		x = a[x];
	return x;
}
bool join(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
	{
		a[fy] = fx;
		return true;
	}
	else return false;
}
bool cmp(Edge E1, Edge E2)
{
	return E1.weight < E2.weight;
}
int main()
{
	int n, m, i, sum = 0, cnt = 0, max = -1;
	cin >> n >> m;
	Init();
	Edge E[9000];
	for (i = 0; i < m; i++)
		cin >> E[i].u >> E[i].v >> E[i].weight;
	sort(E, E + m, cmp);
	for (i = 0; i < m; i++)
	{
		if (join(E[i].u, E[i].v))
		{
			if (max < E[i].weight) max = E[i].weight;
			sum += E[i].weight;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	cout << cnt << " " << max << endl;
	return 0;
}