#include <iostream>
#include<string.h>
using namespace std;
int gs = 0;
int ma[10002];//是否出现
int ss[10002];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l; cin >> l;
		ma[l] = 1;
		ss[i] = l;

	}
	for (int i = 0; i < n; i++)
	{
		if (ma[ss[i] - 1])gs++;
		if (ma[ss[i] + 1])gs++;
	}
	cout << gs / 2 << endl;
	return 0;
}