#include<iostream>
#include<algorithm>
using namespace std;
int F[1501];
struct Point
{
	int from;
	int to;
	int w;
}point[1501];

bool cmp(Point x, Point y)
{
	return x.w < y.w;
}

int find(int x)
{
	if (F[x] == x)
		return F[x];
	else
		return F[x] = find(F[x]);
}

bool fun(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x != y)
	{
		F[y] = x;
		return true;
	}
	return false;
}

int main()
{
	int n, e, i;
	while (scanf("%d%d", &n, &e) != EOF)
	{
		int total = 0, cnt = 0;
		for (i = 0; i < e; i++) {
			scanf("%d%d%d", &point[i].from, &point[i].to, &point[i].w);
		}
		for (i = 0; i < n; i++)
			F[i] = i;
		sort(point, point + e, cmp);
		for (i = 0; i < e; i++)
		{
			if (fun(point[i].from, point[i].to)) {
				total += point[i].w;
				cnt++;
			}
			if (cnt == n - 1)break;
		}
		if (cnt == n - 1) cout << total << endl;
		else cout << "There is no minimum spanning tree." << endl;
	}
}