#include<iostream>
#include<algorithm>
using namespace std;
int xn, xon, x[1000010];
bool juidge(int mid)
{
	int i, cnt = 1;
	int last = 1;
	for (i = 2; i <= xn; i++)
	{
		if (x[i] - x[last] >= mid)
		{
			cnt++;
			last = i;
		}
	}
	if (cnt >= xon) return true;
	else return false;
}
int main()
{
	int i;
	cin >> xn >> xon;
	for (i = 1; i <= xn; i++)
	{
		cin >> x[i];
	}
	sort(x + 1, x + 1 + xn);
	int l = 1, r = x[xn] - x[1];
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (juidge(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << endl;
	return 0;
}
