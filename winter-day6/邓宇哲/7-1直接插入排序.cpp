#include <iostream>
#include <cstring>
using namespace std;
main()
{
	int list[105];
	int n;
	while (cin >> n)
	{
		memset(list, 0, sizeof(list));
		for (int i = 1; i <= n; i++)
		{
			cin >> list[i];
		}
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (list[i] >= list[j - 1] && list[i] <= list[j])
				{
					int t = list[i];
					for (int m = i; m >= j + 1; m--)
					{
						list[m] = list[m - 1];
					}
					list[j] = t;
					break;
				}
			}
			for (int j = 1; j < n; j++)
			{
				cout << list[j] << ' ';
			}
			cout << list[n] << endl;
		}
	}
}