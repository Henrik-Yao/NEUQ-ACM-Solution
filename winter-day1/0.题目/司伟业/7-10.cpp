#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
struct person{
	string name;
	int arrival,deal;
}p[maxn];
vector <string> v[105];
vector <person> friends[maxn];
map <string,int> id;
int n,m,late;
double ans;
bool check[maxn];
int lists[maxn];
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
			person nt = friends[i][j];
			if (late >= nt.arrival)
			{
				int t = id[nt.name];
				late += nt.deal;
				lists[++lists[0]] = t;
				check[t] = 1;
				cout << nt.name << endl;
			}
		}
	}
	late = 0;
	for (int i = 1;i <= n; i++)
	{
		if (p[lL[i]].arrival >= late)
		{
			late = p[lL[i]].arrival + p[lL[i]].deal;
		} else {
			ans += late - p[lL[i]].arrival;
			late += p[lL[i]].deal;
		}
	}
	ass = ass * 1.0 / n;
	printf("%.1f\n",ass);
	return 0;
}
