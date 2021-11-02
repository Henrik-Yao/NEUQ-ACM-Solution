#include<iostream>
#include<cmath>
using namespace std;
int F[65];
int main()
{
	int n, i, j;
	uint64_t min, cnt;
	F[1] = 1;
	F[2] = 3;
	min = UINT64_MAX;
	for (i = 3; i < 65; i++)
	{
		for (j = 1; j < i; j++)
		{
			cnt = 2 * F[j] + pow(2, i - j) - 1;
			if (min > cnt) min = cnt;
		}
		F[i] = min;
		min = UINT64_MAX;
	}
	while (cin >> n)
		cout << F[n] << endl;
	return 0;
}