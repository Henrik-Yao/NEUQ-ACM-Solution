#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
vector<int>a;

bool check(int min) {
	int cnt = 1, cur = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - a[cur] >= min) {
			cur = i;
			++cnt;
		}
	}
	return cnt >= m;
}

int main() {
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.emplace_back(temp);
	}
	sort(a.begin(), a.end());
	int left = 0, right = a[n - 1] - a[0];
	int mid;
	while (left < right) {
		mid = (left + right +1) >> 1;
		if (check(mid))left = mid;
		else right = mid - 1;
	}
	cout << left;
}