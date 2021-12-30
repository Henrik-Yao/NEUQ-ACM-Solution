#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[1005],tot[10005];
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
		tot[a[i]]++;
	}
	for (int i = 1;i <= n; i++)
	{
		ans += tot[a[i] + 1];
	}
	printf("%d\n",ans);
	return 0;
}
