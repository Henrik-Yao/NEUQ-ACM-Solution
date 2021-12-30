#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
int main()
{
	
	while(scanf("%d",&n) != EOF)
	{
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",a + i);
		}
		for (int i = 2;i <= n; i++)
		{
			sort(a + 1,a + i + 1);
			for (int j = 1;j <= n; j++)
			{
				printf("%d%c",a[j]," \n"[j == n]);	
			}
		}
	}
	
	return 0;
}
