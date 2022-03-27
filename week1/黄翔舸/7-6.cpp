#include<iostream>
using namespace std;
int main()
{
	int max(int x, int y);
	int n, T;
	cin >> n >> T;
	int m = -10000000;
	int i = 1;
	while (i <= n)
	{
		int v, t;
		cin >> v >> t;
		if (T >= t)

			m = max(v, m);
		else
			m = max((v - t + T), m);



		i++;
	}
	cout << m << endl;



	return 0;
}
int max(int x, int y)
{
	return x > y ? x : y;
}