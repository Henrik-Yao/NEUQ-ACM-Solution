#include <bits/stdc++.h>
using namespace std;
struct score{
	string name;
	int t;
}p[25];
int n;
bool cmp(score &x,score &y)
{
	if (x.t != y.t) return x.t > y.t;
	return x.name < y.name;
}
int main()
{
	cin >> n;
	for (int i = 1;i <= n; i++)
	{
		cin >> p[i].name >> p[i].t;
	}
	sort(p + 1,p + n + 1,cmp);
	for (int i = 1;i <= n; i++)
	{
		cout << p[i].name << " " << p[i].t << endl;
	}
	return 0;
}
