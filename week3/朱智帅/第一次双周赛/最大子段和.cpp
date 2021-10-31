#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<string.h>
#include<vector>
using namespace std;
int64_t Han[1000001];
int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> Han[i];
	}
	int sum = 0, maxsum = 0, nowmaxsum = 0;
	for (i=0; i < n; i++)
	{
		if (Han[i] > 0) break;
	}
	for (; i < n; i++)
	{
		sum += Han[i];
		if (sum < 0) sum = 0;
		else if (sum > maxsum) maxsum = sum;
	}
	cout << maxsum << endl;
	return 0;
}