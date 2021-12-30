#include <iostream>
using namespace std;
int a[1024];
int n;
void sort(int, int);
main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void sort(int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int temp = a[l];
	int i = l, j = r;
	while (i < j)
	{
		while (a[j] > temp && j > i)
			j--;
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			swap(a[j], a[i]);
		}
	}
	swap(a[i], a[l]);
	for (int o = 0; o < n; o++)
	{
		cout << a[o] << " ";
	}
	cout << endl;
	sort(l, i - 1);
	sort(j + 1, r);
}