#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int a = 2;
		for (int i = 1; i < n; i++) {
			a = a * 3 + 2;
		}
		cout << a << endl;
	}
	return 0;
}
