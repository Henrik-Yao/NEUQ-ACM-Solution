#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, lm, lz;
	string mu, zi;

	cin >> n;
	cin >> mu;

	lm = mu.length();
	for (int i = 0; i < n; i++) {
		cin >> zi;
		lz = zi.length();
		int count = 0;
		for (int j = 0; j < lm - lz + 1; j++) {
			string a = mu.substr(j, lz);
			if (a == zi)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}