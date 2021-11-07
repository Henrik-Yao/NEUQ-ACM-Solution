#include <iostream>
using namespace std;
long long dg(int q1, int q2, int* a,int* c, long long end)
{
	if (q2 - q1 == 1)
	{
		if (a[q1] > a[q2])
		{
			int zj = a[q1];
			a[q1] = a[q2];
			a[q2] = zj;
			end++;
		}
		return end;
	}
	else if (q2 - q1 > 1)
	{
		long long end_copy1,end_copy2;
		end_copy1=dg(q1, (q1 + q2) / 2, a, c, end);
		end_copy2=dg((q1 + q2) / 2 + 1, q2, a, c, end);
		end = end_copy1 + end_copy2;
		int mid = (q1 + q2) / 2;
		int qw = mid + 1;
		int as = q1;
		int q11 = q1;
		while (q11 <= mid && qw <= q2)
		{
			if (a[q11] > a[qw])
			{
				c[as++] = a[qw++];
			}
			else
			{
				c[as++] = a[q11++];
				end = end + qw - mid-1;
			}
		}
		while (q11 <= mid)
		{
			c[as++] = a[q11++];
			end = end + q2 - mid;
		}
		while (qw <= q2)
		{
			c[as++] = a[qw++];
		}
		for (int i = q1; i <= q2; i++)
		{
			a[i] = c[i];
		}
		return end;
	}
	else return 0;
}
int c[1000006];
int a[1000006];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int q1 = 1, q2 = n;
	long long end=0;
	end=dg(q1, q2, a, c, end);
	cout << end;
}