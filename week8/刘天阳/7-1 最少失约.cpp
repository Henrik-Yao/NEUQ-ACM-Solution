#include<bits/stdc++.h>
using namespace std;
struct Thing{
	int a, b;
}a[1009];
bool cmp(Thing a, Thing b)
{
	return a.b < b.b;
}
int main()
{
	int t; cin >> t;
	while(t--) 
	{
		int n, ans = 0; cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b;
		sort(a+1, a+n+1, cmp);
		int t = 0;
		for (int i = 1; i <= n; i++) 
		{
			if(a[i].a >= t) 
			{
				ans++; t = a[i].b;
			}
		}
		cout << n-ans << endl;
	}

	return 0;
}
