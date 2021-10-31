#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
	int n, tar;
	cin >> n >> tar;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	int left = 1;
	int right = n;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (tar > a[mid])
			left = mid + 1;
		else
			right = mid;
	}
	if (a[left] >= tar)
		cout << left;
	else cout <<n + 1;
	cout << endl;
	return 0;
}

