#include<iostream>
#include<algorithm>
using namespace std;
int a[200];
struct Edge
{
	int u, v, weight;
};
void Init()
{
	int i;
	for (i = 0; i < 200; i++)
		a[i] = i;
}
int find(int x)
{
	int r = x;
	while (r != a[r])
		r = a[r];
	return r;
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
{int n, m, i, sum, cnt;
	while (cin>>n>>m) {
		sum = 0, cnt = 0;
		Init();
		Edge E[200];
		for (i = 0; i < m; i++)
			cin >> E[i].u >> E[i].v >> E[i].weight;
		sort(E, E + m, cmp);
		for (i = 0; i < m; i++)
		{
			if (join(E[i].u, E[i].v))
			{
				sum += E[i].weight;
				cnt++;
			}
			if (cnt == n - 1) break;
		}
		if (cnt == n - 1) cout << sum << endl;
		else cout << "There is no minimum spanning tree." << endl;
	}
	return 0;
}