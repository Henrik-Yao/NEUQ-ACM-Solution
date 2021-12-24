#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int f[N+5], a[N+5];
int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)	cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 2; i <= n; i++)	f[i-1] = a[i] - a[i-1] - 1;
	sort(f+1,f+n);
	int ans = n;
	if(n > m)
	{
		for (int i = 1; i <= n-m; i++) ans += f[i];
	}
	cout << ans;
	return 0;
}
