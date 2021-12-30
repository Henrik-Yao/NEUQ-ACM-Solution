#include <bits/stdc++.h>
using namespace std;
int n,x,cnt;
int a[1005];
int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n; i++)
		scanf("%d",a + i);
	scanf("%d",&x);
	int l = 0,r = n - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		cnt++;
		if (a[mid] == x) 
		{
			printf("%d\n%d\n",mid,cnt);
			return 0;
		} else if (a[mid] < x)
		{
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("-1\n%d\n",cnt);
	return 0;
}
