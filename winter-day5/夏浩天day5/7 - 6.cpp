#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[101];
int f;
int en;
int main()
{
	int n;
	while (cin >> n)
	{
		f = 0;
		memset(a, 0, 101);
		en = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			if (f)
				cout << " " << a[i];
			else { cout << a[i]; f = 1; }
		}
		f = 0; cout << endl;
		int m; cin >> m;
		while (m--)
		{
			en = 0;
			int s; cin >> s;
			int q1 = 0, q2 = n - 1;
			int mid = (q1 + q2) / 2;
			while (q1 <= q2)
			{
				if (a[mid] < s) { q1 = mid+1; mid = (q1 + q2) / 2; }
				else if (a[mid] > s) { q2 = mid-1; mid = (q1 + q2) / 2; }
				else { en = mid+1; break; }
			}
			if (f)cout << " " << en;
			else { cout << en; f = 1; }
		}
		cout << endl;
	}
}
