#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, a[1000], b[1000];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j] && b[j] > b[i] - 1) {
					b[i] = b[j] + 1;
				}
			}
		}
		int m = b[0];
		for (int i = 1; i < n; i++) {
			if (b[i] > m)
				m = b[i];
		}
		cout<<m<<endl;
		if (t)
			cout << endl;
	}
}