#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define maxn 10010
struct Node
{
	string name;
	int arrive, cost;
};
Node People[maxn];
int main()
{
	int N, M;
	cin >> N >> M;
	int i, j, k;
	vector<string> friends[maxn];
	map<string, int>number, noder;
	for (i = 1; i <= M; i++)
	{
		int num;
		cin >> num;
		for (j = 0; j < num; j++)
		{
			string s;
			cin >> s;
			number[s] = i;
			friends[i].push_back(s);
		}
	}
	for (i = 1; i <= N; i++)
	{
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (b > 60) b = 60;
		People[i] = { s,a,b };
		noder[s] = i;
	}
	vector<int>oreder[maxn];
	for (i = 1; i <= M; i++)
	{
		for (j = 0; j < friends[i].size(); j++)
		{
			int x = noder[friends[i][j]];
			oreder[i].push_back(x);
		}
		sort(oreder[i].begin(), oreder[i].end());
	}
	bool finished[maxn] = { 0 };
	int time = 0, ans = 0;
	for (i = 1; i <= N; i++)
	{
		if (finished[i]) continue;
		finished[i] = 1;
		cout << People[i].name << endl;
		if (People[i].arrive >= time) time = People[i].arrive + People[i].cost;
		else
		{
			ans = ans + time - People[i].arrive;
			time = time + People[i].cost;
		}
		int x = number[People[i].name];
		for (j = 0; j < oreder[x].size(); j++)
		{
			int t = oreder[x][j];
			if (finished[t]) continue;
			if (People[t].arrive <= time)
			{
				finished[t] = 1;
				ans = ans + time - People[t].arrive;
				time = time + People[t].cost;
				cout << People[t].name << endl;
			}
		}
	}
	printf("%.1f", ans * 1.0 / N);
	return 0;
}