#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a[1009];
	while(cin >> n)
	{
		int k = n;
		for (int i = 1; i <= n; i++) cin >> a[i];
//		for (int i = 1; i <= n; i++) {
//			cout << a[i];
//			if(i < n) cout << " ";
//			else cout << endl;
//		}
		sort(a+1, a+1+n);
		for (int i = 1; i <= n; i++) {
			cout << a[i];
			if(i < n) cout << " ";
			else cout << endl;
		}
		int m; cin >> m;
		while(m--) 
		{
			int b, ans = 0; cin >> b;
			for (int i = 1; i <= n; i++) 
				if(a[i] == b) ans = i;
			cout << ans;
			if(m) cout << " ";
			else cout << endl;
		}
	}
	
	return 0;
}
