#include <bits/stdc++.h>
using namespace std;
int a[100005];
int n, m;

int check(int x) {
	int sign = x + a[1];
	int sum = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] < sign)
			continue;
		sign = a[i] + x;
		sum++;
	}
	return sum >= m;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	int l = 0, r = a[n] - a[1], mid;
	while (l <= r) { //二分查找最小的间隔
		mid = (r + l) >> 1;
		if (check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d\n", r);
	return 0;
}