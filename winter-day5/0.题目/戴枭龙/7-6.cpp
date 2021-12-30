#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			if (i) {
				cout << " ";
			}
			cout << a[i];
		}
		cout << endl;
		int m, count = 0;
		cin >> m;
		while (m--) {
			int t;
			cin >> t;
			int w = lower_bound(a, a + n, t) - a;
			if (!count)
				count++;
			else
				cout << " ";
			if (a[w] == t)
				cout << w + 1;
			else
				cout << 0;
		}
		cout << endl;
	}
}