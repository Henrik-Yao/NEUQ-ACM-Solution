#include<iostream>

int num[100005];
int temp[100005];
using namespace std;

void merge_sort(int x, int y) {
	if (y - x > 1) {
		int m = x + (y - x) / 2;
		merge_sort(x, m);
		merge_sort(m, y);
		int p = x, q = m, i = x;
		while (p < m || q < y)
		{
			if (q >= y || (p < m && num[p] <= num[q]))temp[i++] = num[p++];
			else temp[i++] = num[q++];
		}
		for (i = x; i < y; i++)num[i] = temp[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	merge_sort(0, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << num[i] << " ";
	}
}