#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

const int maxn = 5*1e5 + 5;

long num[maxn];
long temp[maxn];
long cnt = 0;

void merge_sort(int x, int y) {
	if (y - x > 1) {
		int m = x + (y - x) / 2;
		merge_sort(x, m);
		merge_sort(m, y);
		int p = x, q = m, i = x;
		while (p < m || q < y)
		{
			if (q >= y || (p < m && num[p] <= num[q]))temp[i++] = num[p++];
			else {
				temp[i++] = num[q++];
				cnt += m - p;
			}
		}
		for (i = x; i < y; i++)num[i] = temp[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	merge_sort(0, n);
	cout << cnt;
}