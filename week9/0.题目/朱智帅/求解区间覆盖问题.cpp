#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m, i, pos[10005], len[10005];
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> pos[i];
	}
	sort(pos, pos + n);
	int maxlen = pos[n - 1] - pos[0] + 1;
	//cout << maxlen << endl;
	for (i = 1; i < n; i++)
	{
		len[i - 1] = pos[i] - pos[i - 1];
		//cout << len[i - 1] << endl;
	}
	sort(len, len + n - 1);
	for (i = 1; i < m; i++)
	{
		maxlen = maxlen - len[n - 1 - i] + 1;
	}
	cout << maxlen << endl;
	return 0;
}