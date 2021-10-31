#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a[101];
	int b[101];
	int c[200];
	int t;
	cin >> t;
	int j;
	for (int i = 1; i <= t; i++)
	{
		j = 0;

		int m;
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> a[i];
			c[j] = a[i];
			j++;
		}
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			c[j] = b[i];
			j++;
		}
		sort(c, c + j, less<int>());
		for (int i = 0; i < (n + m); i++)
		{
			if (i == n + m - 1)
			{
				cout << c[i] << endl;
			}
			else
				cout << c[i] << " ";
		}
	}

	return 0;
}

