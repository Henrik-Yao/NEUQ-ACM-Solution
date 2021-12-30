#include <iostream>
using namespace std;
int sum = 0;
int a[10009];
int ans = -1;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> x;
	int l = 0, r = n - 1;
	while (l <= r)
	{
		sum++;
		int m = (l + r) / 2;
		if (x == a[m]) { ans = m; break; }
		if (x > a[m]) l = m + 1;
		else r = m - 1;
	}
	cout << ans << endl << sum << endl;
	return 0;
}