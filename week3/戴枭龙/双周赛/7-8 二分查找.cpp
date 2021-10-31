#include <bits/stdc++.h>
using namespace std;
int a[1000010];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int i = 1, j = n, mid;
	while (i <= j) {
		mid = (i + j) / 2;
		if (m <= a[mid])
			j = mid - 1;
		else
			i = mid + 1;
	}
	if (a[i] >= m)
		cout << i ;
	else
		cout << n + 1 ;
	return 0;
}