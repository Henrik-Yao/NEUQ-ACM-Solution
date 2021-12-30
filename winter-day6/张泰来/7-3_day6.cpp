#include <bits/stdc++.h>
using namespace std;
int n,t;
int cnt[55];
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",&t);
		cnt[t]++;
	}
	for (int i = 0;i <= 50; i++)
	{
		if (!cnt[i]) continue;
		cout << i << ":" << cnt[i] << endl; 
	}
	return 0;
}
