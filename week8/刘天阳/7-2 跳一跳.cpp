#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N+9];
int main()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int k = 1, ans = 1;
	while(k+a[k] < n) 
	{
		int p = a[k], maxx = k+1, l = k+1;
		for(int i = k+1; i <= k+p; i++)
		{
			if(a[i]+i >= maxx) maxx = a[i]+i, l = i; 
		}
		k = l;
//		printf("k = %d\n", k);
		ans++;
	}
	cout << ans;
	return 0;
}
