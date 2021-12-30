#include <bits/stdc++.h>
using namespace std;
int sum = 0;
int erf(int a[], int x, int n)
{
	int l = 0, r = n-1;
	while(l <= r)
	{
		sum++;
		int m = (l+r)/2;
		if(x == a[m]) return m;
		if(x > a[m]) l = m + 1;
		else r = m - 1;
	}
	return -1;
}
int main()
{
	int n, a[10009], x, ans;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> x;
	
	ans = erf(a, x, n);
	cout << ans << endl << sum;
	return 0;
}
