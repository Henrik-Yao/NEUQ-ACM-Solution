#include <bits/stdc++.h>
using namespace std;
struct person{
	string name;
	int arrival,deal;
}p[10005];
vector <string> v[105];
vector <person> friends[10005];
map <string,int> id;
int n,m,late;
double ans;
bool check[10005];
int lists[10005];
bool cmp(person &x,person &y)
{
	if (x.arrival != y.arrival) return x.arrival < y.arrival;
	return id[x.name] < id[y.name];
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= m; i++)
	{
		int t;
		cin >> t;
		for (int j = 1;j <= t; j++)
		{
			string name;
			cin >> name;
			v[i].push_back(name);
		}
	}
	for (int i = 1;i <= n; i++)
	{
		cin >> p[i].name >> p[i].arrival >> p[i].deal;
		id[p[i].name] = i;
		p[i].deal = min(p[i].deal,60);
	}
	for (int i = 1;i <= m; i++)
	{
		for (int j = 0;j < v[i].size(); j++)
		{
			for (int k = j + 1;k < v[i].size(); k++)
			{
				int x = id[v[i][j]];
				int y = id[v[i][k]];
				if (cmp(p[x],p[y]))
				{
					friends[x].push_back(p[y]);
				} else {
					friends[y].push_back(p[x]);
				}
			}
		}
	}
	for (int i = 1;i <= n; i++)
	{
		sort(friends[i].begin(),friends[i].end(),cmp);
	}
	late = 0;
	for (int i = 1;i <= n; i++)
	{
		if (check[i]) continue;
		check[i] = 1;
		lists[++lists[0]] = i;
		cout << p[i].name << endl;
		if (late > p[i].arrival) late += p[i].deal;
		else late = p[i].arrival + p[i].deal;
		for (int j = 0;j < friends[i].size(); j++)
		{
			person next = friends[i][j];
			if (late >= next.arrival)
			{
				int t = id[next.name];
				late += next.deal;
				lists[++lists[0]] = t;
				check[t] = 1;
				cout << next.name << endl;
			}
		}
	}
	late = 0;
	for (int i = 1;i <= n; i++)
	{
		if (p[lists[i]].arrival >= late)
		{
			late = p[lists[i]].arrival + p[lists[i]].deal;
		} else {
			ans += late - p[lists[i]].arrival;
			late += p[lists[i]].deal;
		}
	}
	ans = ans * 1.0 / n;
	printf("%.1f\n",ans);
	return 0;
}
