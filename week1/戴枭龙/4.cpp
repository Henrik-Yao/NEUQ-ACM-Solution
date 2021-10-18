#include <bits/stdc++.h>
using namespace std;
int f[10000] ;

int main() {
	int n;
	cin >> n;

	f[1] = 2;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i / 2; j++) {
			if (i % j == 0)
				f[i] = f[i] + f[j];
		}
	}
	cout << f[n];
}