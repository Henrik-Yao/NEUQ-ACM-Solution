#include<iostream>

long long num[1000005];
long long cht = 0;
long long temp[1000005];
using namespace std;

void merge_sort(long long x, long long y) {
	if (y - x > 1) {
		long long m = x + (y - x) / 2;
		merge_sort(x, m);
		merge_sort(m, y);
		long long p = x, q = m, i = x;
		while (p < m || q < y)
		{
			if (q >= y || (p < m && num[p] <= num[q]))temp[i++] = num[p++];
			else {
				temp[i++] = num[q++];
				cht += m - p;
			}
		}
		for (i = x; i < y; i++)num[i] = temp[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	long long n; cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	merge_sort(0, n);
	cout << cht<<endl;
}