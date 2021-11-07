#include <iostream>
using namespace std;
bool ispri[10000005] = {1, 1};
long pri[1000000] = {0};
long point = 0;
main()
{
	
	for (long i = 2; i <= 10000000; i++)
	{
		if (ispri[i] == 0)
		{
			pri[point] = i;
			point++;
		}
		for (long j = 0; j < point; j++)
		{
			if (i * pri[j] > 10000000)
				break;
			ispri[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
	long n,sum=0;
	cin>>n;
	for (long i = 1; i <=n;i++)
	{
		if(ispri[i]==0)
		{
			sum++;
		}
	}
	cout << sum;
}