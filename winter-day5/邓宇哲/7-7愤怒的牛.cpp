#include <bits/stdc++.h>
using namespace std;
int n, m, a[200000];
bool check(int mid)
{
	int tri = 1, point = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (a[i] - a[tri] >= mid)
		{
			tri = i;
			point++;
		}
	}
	return point >= m;
}
main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 0, r = 1061109567, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid + 1, ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << "\n";
}