#include <bits/stdc++.h>
using namespace std;
int a,b;
bool is_prime[10005];
int main()
{
	for (int i = 2;i <= 10000; i++)
		is_prime[i] = 1;
	for (int i = 2;i <= 10000; i++)
	{
		for (int j = i;j * i <= 10000; j++)
		{
			is_prime[i * j] = 0;
		}
	}
	while (scanf("%d%d",&a,&b) != EOF)
	{
		bool f = 0;
		for (int i = a;i <= b; i++)
		{
			if (!is_prime[i]) continue;
			if (!f)
			{
				f = 1;
				printf("%d",i);
			} else {
				printf(" %d",i);
			}
			
		}
		printf("\n");
	}
	return 0;
} 
