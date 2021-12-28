#include <iostream>
#include<algorithm>
using namespace std;

int n, p, e, fa[1001];

struct braige {
	int s, e, v;
}mp[1001];

int find(int a)
{
	if (a == fa[a]) return a;
	else return fa[a] = find(fa[a]);
}

void mergency(int x, int y)
{
	fa[find(x)] = fa[y];
}

bool cmp(braige a, braige b)
{
	return a.v < b.v;
}

int main() {
	while (cin >> n >> p >> e)
	{
		int in = 0, pay = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
		}
		for (int i = 1; i <= e; i++)
		{
			cin >> mp[i].s >> mp[i].e >> mp[i].v;
		}
		sort(mp + 1, mp + e + 1, cmp);
		for (int i = 1; i <= e; i++) {
			if (find(mp[i].s) == find(mp[i].e) || ((mp[i].s == p) || (mp[i].e == p)) && (in == 2)) continue;
			ans = ans + mp[i].v;
			if ((mp[i].s == p) || (mp[i], e == p)) in++;
			mergency(mp[i].s, mp[i].e);
			pay++;
		}
		if (pay == n - 1) cout << ans << endl;
		else cout << "-1" << endl;
	}
	return 0;
}