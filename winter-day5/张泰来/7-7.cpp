#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
bool check(int x)
{
	int sum = 1;
	long long last = a[1];
	for (int i = 2;i <= n; i++)
	{
		if (last + x <= a[i])
		{
			sum++;
			last = a[i];
		}
	}
	return sum >= m;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
	}
	sort(a + 1,a + n + 1);
	int l = 0,r = 2147483647;
	while (r - l > 1)
	{
		int mid = l + (r - l) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n",l);
	return 0;
}
