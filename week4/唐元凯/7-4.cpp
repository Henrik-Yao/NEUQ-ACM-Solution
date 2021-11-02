#include<iostream>

using namespace std;

int pow_mod(int a, int n, int m) {
	if (n == 0)return 1;
	int x = pow_mod(a, n / 2, m);
	long long ans = (long long)x * x % m;
	if (n % 2 == 1)ans = ans * a % m;
	return (int)ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << pow_mod(a, b, c) << '\n';
	}
}