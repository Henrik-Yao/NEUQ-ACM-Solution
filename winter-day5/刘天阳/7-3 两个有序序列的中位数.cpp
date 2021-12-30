#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int a[N], b[N];
int main()
{
	int cnt = 0, n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int al = 1, bl = 1, ans = a[1];
	while(cnt < (2*n+1)/2)
	{
		cnt++;
		if(al <= n && (bl == n+1 || a[al] <= b[bl])) {
			ans = a[al];
			al++;
		}
		else {
			ans = b[bl];
			bl++;
		}
//		printf("ans = %d\n",ans);
	}
	cout << ans;
	return 0;
}
