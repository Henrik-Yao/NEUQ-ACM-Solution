#include <iostream>
#include <algorithm>
using namespace std;
int find(int, int *);
int n;
int deep = 0;
main()
{
	while (cin >> n)
	{
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 0; i < n - 1; i++)
		{
			cout << a[i] << ' ';
		}
		cout << a[n - 1]<<endl;
		int k;int t;
		cin >> k;
		for (int i = 0; i < k-1; i++)
		{
			
			cin >> t;
			cout << find(t, a)<<' ';
		}
		cin >> t;
		cout << find(t, a)<<endl;
	}
}
int find(int target, int *list)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		deep++;
		int mid = l + (r - l) / 2;
		if (target == list[mid])
		{
			return mid+1;
		}
		else if (target > list[mid])
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return 0;
}