#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int a[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int curDistance = 0;
	int ans = 0;
	int nextDistance = 0;
	for (int i = 0; i < n - 1; i++) {
		nextDistance = max(a[i] + i, nextDistance);
		if (i == curDistance) {
			curDistance = nextDistance;
			ans++;
		}
	}
	cout << ans << endl;
}