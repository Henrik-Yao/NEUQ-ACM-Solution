#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	int mw[10000];
	int sj[10000];
	int tmp;
	int max1;

	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> mw[i] >> sj[i];
	}

	if (sj[0] > t) {
		max1 = mw[0] + t - sj[0];
	} else
		max1 = mw[0];

	for (int j = 1; j < n; j++) {

		if (sj[j] > t) {
			tmp = mw[j] + t - sj[j];
		} else
			tmp = mw[j];

		if (tmp > max1)
			max1 = tmp;
	}

	cout << max1;
	return 0;
}