#include <bits/stdc++.h>
using namespace std;
int a[10000];

void find(int x, int n) {
	int l = 0, r = n-1, cnt = 0;
	while (l <= r) {
		cnt++;
		int mid = (l + r) / 2; //防止溢出
		if (x == a[mid])
			break;
		if (x < a[mid] )
			r = mid-1;  //小于中间的数，在左区间
		else
			l = mid + 1;  //大于中间的数，在右区间
	}
	if (a[l] == x) {
		cout << l << endl << cnt << endl;
	} else
		cout << -1 << endl << cnt << endl;
}

int main() {
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;
	find(x, n);
	return 0;
}