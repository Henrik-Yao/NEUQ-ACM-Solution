#include <bits/stdc++.h>
using namespace std;

int main() {
	float r, d, n;
	cin >> r >> d >> n;
	d = abs(d);
	n = abs(n);
	if (n - r <= 0)
		cout << fixed << setprecision(2) << 2.00 * d - r;
	else
		cout << fixed << setprecision(2) << 2.00 * sqrt(d * d + (n - r) * (n - r)) - r;
	return 0;
}