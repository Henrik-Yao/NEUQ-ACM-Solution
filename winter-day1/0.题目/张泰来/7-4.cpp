#include <bits/stdc++.h>
using namespace std;
vector <int> v1,v2;
int n;
int a[1000005];
int main()
{
	while (cin >> a[++n]);
	n--;
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n; i++)
	{
		if (a[i] & 1)
		{
			v1.push_back(a[i]);
		} else {
			v2.push_back(a[i]);
		}
	}
	for (int i = 1;i <= n; i++)
	{
		printf("%d",a[i]);
		if (i < n)
		{
			printf("->");
		} 
	}
	printf("\n");
	for (int i = 0;i < v1.size(); i++)
	{
		printf("%d",v1[i]);
		if (i < v1.size() - 1)
		{
			printf("->");
		}
	}
	printf("\n");
	for (int i = 0;i < v2.size(); i++)
	{
		printf("%d",v2[i]);
		if (i < v2.size() - 1)
		{
			printf("->");
		}
	}
	printf("\n");
	return 0;
}

