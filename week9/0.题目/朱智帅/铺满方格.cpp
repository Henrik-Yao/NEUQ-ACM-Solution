#include<iostream>
using namespace std;
int main()
{
	int n, i;
	uint64_t ways[55];
	ways[1] = 1, ways[2] = 2, ways[3] = 4;
	for (i = 4; i <= 50; i++)
	{
		ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
	}
	while (scanf("%d", &n)!=EOF)
	{
		cout << ways[n] << endl;
	}
	return 0;
}