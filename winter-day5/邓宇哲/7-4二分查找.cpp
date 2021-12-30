#include <iostream>
using namespace std;
int find(int, int *);
int n;
int deep=0;
main()
{

	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t;
	cin >> t;
	cout << find(t, a) << endl
		 << deep;
}
int find(int target, int *list)
{
	int l = 0;
	int r = n - 1;
	while (l<=r)
	{
		deep++;
		int mid = l + (r - l) / 2;
		if(target==list[mid])
		{
			return mid;
		}
		else if(target>list[mid])
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return -1;
}