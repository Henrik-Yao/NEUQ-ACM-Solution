#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;
int N;
vector<int>v[10001];
int ways[10001][10001] = { 0 };
int city[10001];
bool ifok(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < v[i].size(); j++)
		{
			if (city[i] == 0 && city[v[i][j]] == 0)
				return false;
		}
	}
	return true;
}
int main()
{
	int n, m, a, b;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int k, nu;
	cin >> k;
	while (k--)
	{
		memset(city, 0, sizeof(city));
		cin >> nu;
		while (nu--)
		{
			cin >> a;
			city[a] = 1;
		}
		if (ifok(n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}