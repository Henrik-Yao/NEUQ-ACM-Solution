#include<iostream>
using namespace std;

int main()
{
	int a[200002], c[100001], i, n, j = 0, k = 0;

	cin >> n;
	for (i = 0; i < 2 * n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++) {
		if (a[k] < a[n + j]) {
			c[i] = a[k];
			k++;
		}
		else {
			c[i] = a[n + j];
			j++;
		}
	}
	cout << c[n - 1];

	return 0;
}