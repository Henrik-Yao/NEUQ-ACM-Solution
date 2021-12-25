#include <bits/stdc++.h>
using namespace std;
long long f[1009];
int main()
{
	f[1] = 1, f[2] = 2, f[3] = 4;
//	int t; cin >> t;
	int n;
	while(cin >> n)
	{
//		int n; cin >> n;
		for(int i = 4; i <= n; i++)
		{
			if(f[i]) continue;
			f[i] = f[i-1]+ f[i-2]+ f[i-3];
		}
		cout << f[n] << endl;
	}
	return 0;
}
