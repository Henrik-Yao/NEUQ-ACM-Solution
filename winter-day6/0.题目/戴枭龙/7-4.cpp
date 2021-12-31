#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, a[maxn], r[maxn];
long long ans = 0;

void mergesort(int s, int e) {
	int i, j, k, m;
	if (s == e)
		return;
	m = (s + e) / 2; //取中点
	mergesort(s, m); //递归左区间
	mergesort(m + 1, e); //递归右区间
	i = s, j = m + 1, k = s;
	while (i <= m && j <= e) { //二路归并（升序）过程
		if (a[i] <= a[j]) {
			r[k] = a[i];
			i++;
			k++;
		} else {
			r[k] = a[j];
			j++;
			k++;
			ans += m - i + 1;
		}
	} //将序列中剩余的元素接入r数组
	while (i <= m) {
		r[k] = a[i];
		i++;
		k++;
	}
	while (j <= e) {
		r[k] = a[j];
		j++;
		k++;
	}
	for (int i = s; i <= e; i++)
		a[i] = r[i]; //数组赋回
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	mergesort(1, n);
	cout << ans << endl;
	return 0;
}