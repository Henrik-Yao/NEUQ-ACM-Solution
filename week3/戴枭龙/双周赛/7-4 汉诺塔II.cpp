#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[66], n;
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i < 65; i++) {
		int min = 666666;
		for (int j = 1; j < i; j++) {
			if (2 * a[j] + pow(2, i - j) - 1 < min)
				min = 2 * a[j] + pow(2, i - j) - 1;
		}
		a[i] = min;
	}
	while (cin >> n) {
		cout << a[n] << endl;
	}
	return 0;
}