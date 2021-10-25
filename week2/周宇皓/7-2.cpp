#include<bits/stdc++.h>
using namespace std;
int n, a[100001], b[100001];
void guibing(int m, int n) {
	if (m == n)
		return;
	int mid = (m +n) / 2;
	guibing(m, mid);
	guibing(mid + 1, n);
	int p = m;
	int q = mid + 1, s = 0;
	while (p <= mid && q <= n) {
		if (a[p] < a[q])
		{
			b[++s] = a[p];
			p++;
		}
		else {
			b[++s] = a[q];
		q++;
		}
	}
	while (p <= mid)
	{
		
		b[++s] = a[p];
		p++;
		
	}
	while (q <= n)
	{
		b[++s] = a[q];
		q++;
		
	}
	for (int i = m; i <= n; i++)
		a[i] = b[i - m + 1];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	guibing(1, n);
	for (int i = 1; i <= n; i++)
		cout << a[i]<<" ";
}

