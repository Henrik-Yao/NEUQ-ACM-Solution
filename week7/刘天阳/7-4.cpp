#include<bits/stdc++.h>
using namespace std;
int a[10009], ans[10009], fans[10009];
int main()
{
	int t;
	cin >> t;
	for(int ii = 1; ii <= t; ii++)
	{
		int n, maxx = 1;
		cin >> n;
		memset(ans,0,sizeof(ans));
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			ans[i] = 1;
			for (int j = 1; j < i; j++)
			{
				if(a[j] < a[i]) ans[i] = max(ans[j]+1, ans[i]);
				maxx = max(maxx, ans[i]);
			}
		}
		cout << maxx << endl;
		if(ii < t)cout << endl;
	}
//	for (int i = 1; i <= t; i++) cout << fans[i] << endl << endl;
	return 0;
}
