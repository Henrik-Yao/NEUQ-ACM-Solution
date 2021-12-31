#include<iostream>
#include<queue>
using namespace std;
int visited[1000001] = { 0 };
int len[1000001] = { 0 };
int cnt = 0;
int main()
{
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> len[i];
	}
	int nowmax, nextmax;
	nowmax = 1;
	nextmax = 1 + len[1];
	for (i = 2; i <= n; i++)
	{
		//cout << "nowmax:" << nowmax << "  nextmax:" << nextmax << endl;
		if (i > nowmax)
		{
			cnt++;
			nowmax = nextmax;
		}
		if (i + len[i] > nextmax)
		{
			nextmax = i + len[i];
		}
	}
	cout << cnt << endl;
	return 0;
}