#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int qw = 0; qw < t; qw++)
	{
		int a[100], b[100], m, n;
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> a[i];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> b[i];
		int za = 0, zb = 0;
		int c[200];
		int as = 0;
		while (za < m && zb < n)
		{
			if (a[za] < b[zb])
				c[as++] = a[za++];
			else
				c[as++] = b[zb++];
		}
		while (za < m)
		{
			c[as++] = a[za++];
		}
		while (zb < n)
		{
			c[as++] = b[zb++];
		}
        cout<<c[0];
		for (int i = 1; i < m + n; i++)
		{
			cout <<" "<< c[i];
		}
        cout<<endl;
	}
}