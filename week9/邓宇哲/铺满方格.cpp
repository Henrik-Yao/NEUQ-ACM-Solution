#pragma GCC optimize(3)
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
long long list[51] = {0, 1, 2, 4};
int function(int);
main()
{

	for (int i = 4; i < 51; i++)
	{
		list[i] = list[i - 1] + list[i - 2] + list[i - 3];
	}
	int n;
	while (cin >> n)
		cout << list[n]<<endl;
}
