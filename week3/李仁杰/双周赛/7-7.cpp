#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, * a;
long long ans = 0;

void merge(int lo, int mid, int hi) {
	int i = lo;
	int j = mid + 1;
	int k = 0;
	int* temp = new int[hi - lo + 1];
	while (i <= mid && j <= hi)
		if (a[i] <= a[j])	temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			ans += mid - i + 1;
		}
	while (i <= mid)	temp[k++] = a[i++];
	while (j <= hi)	temp[k++] = a[j++];
	for (int i = 0; i < hi - lo + 1; i++) a[lo + i] = temp[i];
	free(temp);
}

void mergesort(int lo, int hi) {
	if (lo >= hi) return;
	int mid = (lo + hi) / 2;
	mergesort(lo, mid);
	mergesort(mid + 1, hi);
	merge(lo, mid, hi);
}

int main() {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	mergesort(0, n - 1);
	cout << ans;
}