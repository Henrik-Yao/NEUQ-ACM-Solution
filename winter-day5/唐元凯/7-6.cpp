#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int bsearch(vector<int>A, int x, int y, int v) {
	int m;
	while (x <= y) {
		m = x + (y - x) / 2;
		if (A[m] == v)return m;
		else if (A[m] > v)y = m - 1;
		else x = m + 1;
	}
	return -1;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int>num(n);
		for (int i = 0; i < n; i++)
			cin >> num[i];
		sort(num.begin(), num.end());
		for (auto &c : num) {
			cout << c;
			if (&c != &num[n - 1])cout << " ";
		}
		cout << endl;

		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int v;
			cin >> v;
			cout << bsearch(num, 0, n - 1, v) + 1;
			if (i != m - 1)cout << " ";
		}
		cout << endl;
	}
}