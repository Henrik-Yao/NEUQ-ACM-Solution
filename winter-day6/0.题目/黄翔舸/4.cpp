#include<algorithm>
#include<iostream>

#include<cstring> 
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int mxn = 500010;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;

}
int t[mxn], a[mxn];
int n;
long long ans = 0;
void merge(int l, int r) {
	if (l >= r)return;
	int mid = (l + r) >> 1;
	merge(l, mid);
	merge(mid + 1, r);
	int p = l, q = mid + 1, i = l;
	while (p <= mid || q <= r) {
		if (q > r || (p <= mid && a[p] <= a[q])) {
			t[i++] = a[p++];

		}
		else t[i++] = a[q++], ans += mid - p + 1;

	}
	for (i = l; i <= r; i++)a[i] = t[i];
	return;

}
int main() {
	n = read();
	int i, j;
	for (i = 1; i <= n; i++)
		a[i] = read();
	merge(1, n);
	printf("%lld\n", ans);
	return 0;

}