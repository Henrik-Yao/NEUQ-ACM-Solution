#include <iostream>
using namespace std;
int a[100001], b[100001];
int main()
{
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int aq = 1, bq = 1, ans = a[1];
	while (cnt < (2 * n + 1) / 2)
	{
		cnt++;
		if (aq <= n && (bq == n + 1 || a[aq] <= b[bq]))
		{
			ans = a[aq];
			aq++;
		}
		else
		{
			ans = b[bq];
			bq++;
		}
	}
	cout << ans;
	return 0;
}