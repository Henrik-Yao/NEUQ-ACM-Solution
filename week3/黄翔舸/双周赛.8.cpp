#include<iostream>
using namespace std;
#define p 10000000
int num[p];

int main()
{
	int search(int num[], int size, int o);

	long long int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	int res;
	res = search(num, n, m);
	cout << res << endl;








	return 0;
}
int search(int num[], int size, int o)

{
	int left = 0;
	int right = size - 1;

	while (right > left)
	{

		int middle = left + ((right - left) / 2);
		if (o > num[middle])
		{
			left = middle + 1;
		}
		else if (o <= num[middle])
		{
			while (num[middle - 1] >= o)
			{
				middle = middle - 1;
			}

			return middle + 1;

		}




	}


	return size + 1;



}