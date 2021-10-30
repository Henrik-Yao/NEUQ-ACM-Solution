#include<iostream>
#include<algorithm>

using namespace std;
int num[10005], sum[10005];

int main() {
	ios::sync_with_stdio(false);
	int n, temp;
	cin >> n;
	int start = 0, end = 0;
	num[0] = 0; sum[0] = 0;
	bool sign = 1;
	int _max = 0;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> num[i];
		sum[i] = num[i] + sum[i - 1];
		if (sign && sum[i] > 0) {
			sign = 0;
			start = i - 1;
		}
		else if (sum[i] < 0)sign = 1;
		if (sum[i] > sum[i - 1])end = i;
		_max = max(_max, sum[end] - sum[start]);
	}
	cout << _max << endl;
}