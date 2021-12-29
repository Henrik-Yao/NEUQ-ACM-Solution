#include <bits/stdc++.h>
using namespace std;
int n, a[100005];

void quicksort(int a[], int be, int e) {
	if (be >= e)
		return ;
	int i = be, j = e;
	int key = a[i];
	int temp;
	while (i != j) {
		while (i < j && a[j] > key)
			j--;
		while (i < j && a[i] <= key)
			i++;
		if (i < j)
			swap(a[i], a[j]);
	}
	swap(a[be], a[i]);
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
	quicksort(a, be, j - 1);
	quicksort(a, i + 1, e);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quicksort(a, 0, n - 1);
	for (int k = 0; k < n; k++) {
		cout << a[k] << " ";
	}
	cout << endl;
	return 0;
}