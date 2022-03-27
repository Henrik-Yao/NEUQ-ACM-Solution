#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int n;
long long sum = 0;

void mergesort(int L, int R) {
	if (L == R) {
		return ;
	}
	int m = (L + R) / 2;
	int i = L, j = m + 1, k = L;
	mergesort(L, m);
	mergesort(m + 1, R);
	while (i <= m && j <= R) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			k++;
			i++;
		} else {
			b[k] = a[j];
			k++;
			j++;
			sum = sum + m - i + 1;
		}
	}
	while (i <= m)
		b[k++] = a[i++];
	while (j <= R)
		b[k++] = a[j++];
	for (int k = L; k <= R; k++)
		a[k] = b[k];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	mergesort(1, n);
	cout << sum << endl;
	return 0;
}
