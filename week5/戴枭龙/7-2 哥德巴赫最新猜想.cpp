#include <bits/stdc++.h>
using namespace std;

int prime (int p) {
	for (int i = 2; i <= sqrt(p); i++) {
		if (p % i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	for (int j = 1; j <= n; j++) {
		int x;
		cin >> x;
		if (prime(x) == 1)
			cout << 1 << endl;
		else if (x % 2 == 0 || prime(x - 2) == 1)
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}
	return 0;

}