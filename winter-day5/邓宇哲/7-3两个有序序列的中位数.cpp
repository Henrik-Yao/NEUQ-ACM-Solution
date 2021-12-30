#include <iostream>
using namespace std;
main()
{
	int n;
	cin >> n;
	int a[n], b[n], cache[2 * n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	int pointa = 0,pointb = 0,pointc=0;
	while (pointa!=n&&pointb!=n)
	{
		if(a[pointa]>b[pointb])
		{
			cache[pointc++] = b[pointb++];
		}
		else
			cache[pointc++] = a[pointa++];
	}
	while(pointb!=n)
	{
		cache[pointc++] = b[pointb++];
	}
	while(pointa!=n)
	{
		cache[pointc++] = a[pointa++];
	}
	cout << cache[(2 * n - 1) / 2];
}