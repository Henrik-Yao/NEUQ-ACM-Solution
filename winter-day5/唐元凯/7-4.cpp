#include<iostream>
#include<vector>

using namespace std;

int cnt = 0;
int bsearch(vector<int>A, int x, int y, int v) {
	int m;
	while (x <= y) {
		++cnt;
		m = x + (y - x) / 2;
		if (A[m] == v)return m;
		else if (A[m] > v)y = m - 1;
		else x = m + 1;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int>num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int v;
	cin >> v;
	cout << bsearch(num, 0, n-1, v) << endl << cnt;
}