#include <bits/stdc++.h>
using namespace std;
#define maxn 100000010

int a[maxn], b[maxn];

void merge(int a[], int l, int r) {
	int mid = (l + r) / 2;
	if (l == r)
		return ;
	merge(a, l, mid);
	merge(a, mid + 1, r);
	int i = l, j = mid + 1;
	int k = 1;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= r)
		b[k++] = a[j++];
	for (int x = l, y = 1; x <= r; x++, y++) {
		a[x] = b[y];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	merge(a, 1, n);
	for (int j = 1; j <= n; j++) {
		cout << a[j] << " ";
	}
	return 0;
}