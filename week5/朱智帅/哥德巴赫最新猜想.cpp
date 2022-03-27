
#include<iostream>
#include<cmath>
using namespace std;
bool ifsu(int n)
{
	int k = sqrt(n);
	int i;
	for (i = 2; i <= k; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		if (t % 2 == 0)
		{
			cout << "2" << endl;
			continue;
		}
		else
		{
			if (ifsu(t))
			{
				cout << "1" << endl;
				continue;
			}
			else if (ifsu(t - 2))
			{
				cout << "2" << endl;
				continue;
			}
			else
			{
				cout << "3" << endl;
			}
		}
	}
	return 0;
}