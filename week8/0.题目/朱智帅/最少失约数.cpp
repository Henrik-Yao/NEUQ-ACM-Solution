#include<iostream>
#include<algorithm>
using namespace std;
struct Time
{
	int S, E;
};
bool cmp(Time T1, Time T2)
{
	return T1.E < T2.E;
}
int main()
{
	int T, n, i, j;
	cin >> T;
	while (T--)
	{
		int cnt = 1;
		cin >> n;
		Time Item[1005];
		int maxfinished[25] = { 0 };
		for (i = 0; i < n; i++)
		{
			cin >> Item[i].S >> Item[i].E;
		}
		sort(Item, Item + n, cmp);
		int End = Item[0].E;
		for (i = 1; i < n; i++)
		{
			if (Item[i].S >= End)
			{
				cnt++;
				End = Item[i].E;
			}
		}
		cout << n-cnt << endl;
	}
	return 0;
}