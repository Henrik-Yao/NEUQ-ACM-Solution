#include <bits/stdc++.h>
using namespace std;
long long a[1000001], cache[1000001];
long long sum = 0, k = 1;
void count(int, int);
main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	count(1, n);
	cout << sum;
}
void count(int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	count(l, mid);
	count(mid + 1, r);
	k = 1;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (a[i] > a[j])
		{
			sum += (mid - i + 1);
			cache[k++] = a[j++];
		}
		else
			cache[k++] = a[i++];
	}
	while (i <= mid)
		cache[k++] = a[i++];
	while (j <= r)
		cache[k++] = a[j++];
	for (int m = 1; m < k; m++)
		a[m + l - 1] = cache[m];
}