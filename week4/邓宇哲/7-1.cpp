#include <iostream>
using namespace std;
bool ispri[10011] = {1, 1};
int pri[10000] = {0};
main()
{
	int point = 0;
	for (int i = 2; i <= 10000; i++)
	{
		if (ispri[i] == 0)
		{
			pri[point] = i;
			point++;
		}
		for (int j = 0; j < point; j++)
		{
			if (i * pri[j] > 10000)
				break;
			ispri[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
	int n, m;
	while (cin >> n >> m)
	{
		int a[10000],k=0;
		for (int i = n; i <= m; i++)
		{
			if (ispri[i] == 0)
			{
				a[k] = i;
				k++;
			}
		}
		for (int i = 0; i < k-1;i++)
		{
			cout << a[i] << ' ';

		}
		cout << a[k - 1] << endl;
	}
}