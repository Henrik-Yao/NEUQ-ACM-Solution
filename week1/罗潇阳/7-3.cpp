#include<bits/stdc++.h>
using namespace std;

typedef long double let;

const let eps = 1e-8;

let dist(let x1, let y1, let x2, let y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	let r, d, n;
	cin >> r >> d >> n;
	if (d < 0) d = -d;
	if (n < 0) n = -n;
	if (2.0 * d <= r) {
		if (dist(0, 0, d, n) <= r) puts("0.00");
		else printf("%.2Lf\n", dist(0, 0, d, n) - r);
	} else if (dist(0, 0, d, n) <= r || n <= r) {
		printf("%.2Lf\n", 2.0 * d - r);
	} else {
		printf("%.2Lf\n", 2.0 * dist(0, 0, d, n - r) - r);
	}
	return 0;
}
