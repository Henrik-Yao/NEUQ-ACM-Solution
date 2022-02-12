#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, a[100], cnt = 0;;
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + x + 1);
	for (int i = 1; i < x; i++) {
		if (abs(a[i] - a[i + 1] ) == 1)
			cnt++;
	}
	cout << cnt;
}