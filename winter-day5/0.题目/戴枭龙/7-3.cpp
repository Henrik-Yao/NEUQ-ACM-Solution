#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[100005];
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a, a + 2 * n);
	cout << a[n - 1];
	return 0;
}