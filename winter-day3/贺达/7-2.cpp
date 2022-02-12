#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	map<int, map<int, int>>mp;//输入
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		mp[a][b] = c;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i)//去边
	{
		int a, b;
		cin >> a >> b;
		mp[a].erase(b);
	}

	// 打印
	for (auto i:mp)
	{
		int a = i.first;
		if(!i.second.empty()) cout << a << ":";
		for (auto j : i.second)
		{
			printf("(%d,%d,%d)", a, j.first, j.second);
		}
		if(!i.second.empty()) cout << endl;
	}

	return 0;
}
