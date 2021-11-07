#include<iostream>
using namespace std;
int main()
{
	int y;
	cin >> y;
	int fei(int n);
	for (int i = 1; i <= y; i++)
	{
		int u;
		cin >> u;
		cout << fei(u) << endl;
	}




}
int fei(int n)
{
	int sum = 0;
	if (n == 1)
		sum = 0;
	else if (n == 2)
		sum = 1;
	else if (n == 3)
		sum = 2;
	else
	{
		sum = fei(n - 1) + fei(n - 2);
	}

	return sum;

}