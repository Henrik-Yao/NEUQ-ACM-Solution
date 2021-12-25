#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>next(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> next[i];
	}
	int cur = 1, cnt = 0;
	while (true) {
		if (cur + next[cur] >= n) {
			cnt++;
			break;
		}
		int maxv = 0, maxpos = 1, bestans = 0;
		for (int i = 1, length = next[cur]; i <= length; i++)
		{
			maxv = cur + i + next[cur + i];
			if (maxv >= bestans) {
				bestans = maxv;
				maxpos = cur + i;
			}
		}
		cur = maxpos;
		cnt++;
	}
	cout << cnt;
}