#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[1000005];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
	}
	int pos = lower_bound(a + 1,a + n + 1,k) - a;
	printf("%d\n",pos);
} 
