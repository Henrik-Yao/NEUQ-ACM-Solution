#include <iostream>
using namespace std;
main()
{
	int n;
	int sum = 0;
	cin >> n;
	int list[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (list[i] - list[j] == 1||list[i] - list[j]==-1)
			{
				sum++;
			}
		}
	}
	cout << sum<<endl;
}