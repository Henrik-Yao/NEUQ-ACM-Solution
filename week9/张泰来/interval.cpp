#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[1000005],res[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
	}
	sort(a + 1,a + n + 1);
	ans = a[n] - a[1] + 1;
	for (int i = 1;i < n; i++)
	{
		res[i] = a[i + 1] - a[i] - 1;
	}
	sort(res + 1,res + n,greater<int>());
	for (int i = 1;i < min(n,m); i++)
	{
		ans -= res[i];
	}
	printf("%d\n",ans);
	return 0;
} 
