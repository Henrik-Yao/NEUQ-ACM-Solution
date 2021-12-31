#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int road[n];
	for (int i = 0; i < n; i++)
		cin >> road[i];
	int step = 1;
	int point = 0;
	while (point+road[point]<n-1)
	{
		int max_length = 0;
		int max_point = 1;
		for (int i = 1; i <= road[point] && i < n - point; i++)
		{
			if (i + road[point + i] > max_length)
			{
				max_length = i + road[point + i];
				max_point = i;
			}
		}
		step++;
		point += max_point;
	}
	cout << step << endl;
}