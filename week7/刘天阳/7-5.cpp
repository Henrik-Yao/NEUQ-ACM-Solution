#include<bits/stdc++.h>
using namespace std;
int w[10009], v[10009], ans[10009];
int main()
{
	int n, c;
	while(cin >> n >> c)
	{
		memset(w,0,sizeof(w));
		memset(v,0,sizeof(v));
		memset(ans,0,sizeof(ans));
		for (int i = 1; i <= n; i++) cin >> w[i];
		for (int i = 1; i <= n; i++) cin >> v[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = c; j >= w[i]; j--) ans[j] = max(ans[j], ans[j-w[i]]+v[i]);
		}
		cout << ans[c] << endl;
	}
	return 0;
}
