#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, n = 0, a[1000], a1, a2;
	while (cin >> x) {
		a[n++] = x;
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		cout << a[i]
		     << "->";
		if (a[i] % 2 == 0)
			a2 = i;
		if (a[i] % 2)
			a1 = i;
	}
	cout << a[n - 1] << endl;
	if (a[n - 1] % 2 == 0)
		a2 = n - 1;
	if (a[n - 1] % 2)
		a1 = n - 1;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2)
			if (i == a1) {
				cout << a[i] << endl;
				break;
			} else
				cout << a[i] << "->";
	}
	for (int i = 0; i < n; i++) {
		if (!(a[i] % 2))
			if (i == a2) {
				cout << a[i] << endl;
				break;
			} else
				cout << a[i] << "->";
	}
}