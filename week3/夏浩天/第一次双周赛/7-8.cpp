#include <iostream>
using namespace std;
int a[1000006];
int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int q1 = 1,q2=n;
	if (a[1] >= m)
	{
		cout << "1";
	}
	else if (a[n] < m)
		cout << n + 1 << endl;
	else
	{
		while (q1 <= q2)
		{
			int mid = (q1 + q2) / 2;
			if (a[mid] >= m)
				q2 = mid-1;
			else q1 = mid+1;
		}
		cout << q1<<endl;
	}
}