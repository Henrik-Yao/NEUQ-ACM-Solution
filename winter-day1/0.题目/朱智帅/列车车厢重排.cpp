#include<iostream>
#include<queue>
using namespace std;
queue<int>Q[100];
int Qrear[100] = { 101 };
int main()
{
	int cnt=1;
	int number, n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> number;
		int j;
		bool tag = false;
		for (j = 0; j < cnt-1; j++)
		{
			if (Qrear[j] > number)
			{
				Q[j].push(number);
				Qrear[j] = number;
				tag = true;
				break;
			}
		}
		if (!tag)
		{
			Q[j].push(number);
			Qrear[j] = number;
			cnt++;
		}
	}
	for (i = 0; i < cnt-1; i++)
	{
		if (Qrear[i] == 1) {
			while (Q[i].size())
			{
				cout << Q[i].front();
				Q[i].pop();
				if (Q[i].size()) cout << " ";
			}
			cout << endl;
		}
	}
	cout << cnt - 1 << endl;
	return 0;
}