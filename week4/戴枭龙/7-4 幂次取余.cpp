#include <bits/stdc++.h>
using namespace std;

long long fastPower(long long a, long long b,long long c) {
	long long result = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			result = result * a % c;
		}
		b = b / 2;
		a = (a * a) %c;
	}
	return result;
}


int main() {
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << fastPower(a, b, c) << endl;
	}
	return 0;
}