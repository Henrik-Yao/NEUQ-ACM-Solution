#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[101];
int c[202];

int main() {
	int x, m, n;
	cin >> x;
	while (x--) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		int k = 1, i = 1, j = 1;
		while (i <= m && j <= n) {
			if (a[i] <= b[j]) {
				c[k++] = a[i++];
			} else {
				c[k++] = b[j++];
			}
		}
		while (i <= m)
			c[k++] = a[i++];
		while (j <= n)
			c[k++] = b[j++];
		for (int i = 1; i <= k - 2; i++) {
			cout << c[i] << " ";
		}
		cout << c[k-1] << endl;
	}

	return 0;
}