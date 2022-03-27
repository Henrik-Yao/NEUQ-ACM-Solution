#include<iostream>
using namespace std;
int main()
{


	int n;
	while (cin >> n)
	{
		long long int sum = 1;
		for (int i = 1; i <= n; i++)
		{
			sum *= 3;
		}

		cout << sum - 1 << endl;
	}







	return 0;
}