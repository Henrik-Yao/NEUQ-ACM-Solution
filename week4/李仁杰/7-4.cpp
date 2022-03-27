#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

long long n, a, b, c, ans = 1;

void f() {
	while (b) {
		if (b % 2) ans = ans * a % c;
		b /= 2;
		a = a * a % c;
	}
	cout << ans << endl;
	ans = 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		f();
	}
}