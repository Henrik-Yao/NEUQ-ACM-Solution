#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int ways[41];
int main()
{
	ways[1] = 0, ways[2] = 1, ways[3] = 2;
	int T, M, i;
	for (i = 4; i <= 40; i++)
		ways[i] = ways[i - 1] + ways[i - 2];
	cin >> T;
	while (T--)
	{
		cin >> M;
		cout << ways[M] << endl;
	}
	return 0;
}