#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n) {
		int number[100010], i, j, k;
		
		for (i = 0; i < n; i++) cin >> number[i];
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (number[j] > number[i]) break;
			}
			k = j;
			int temp = number[i];
			for (j = i; j > k; j--)
			{
				number[j] = number[j - 1];
			}
			number[k] = temp;
            cout<<number[0];
			for (j = 1; j < n; j++)
				cout << " "<<number[j];
			cout << endl;
		}
	}
	return 0;
}