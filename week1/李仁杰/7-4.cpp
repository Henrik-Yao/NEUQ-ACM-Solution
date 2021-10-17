#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int f(int n) {
	if (n == 1) return 1;
	int c = 1;
	for (int i = n - 1; i > 1; i--) {
		if (n % i == 0) {
			c += f(i);
		}
	}
	return c + 1;
}

int main() {
	int n;
	cin >> n;
	cout << f(n);
}