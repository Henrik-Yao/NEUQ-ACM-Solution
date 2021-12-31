#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005 ;
int a[maxn], d[maxn] ;

bool cmp(const int &a, const int &b) {
	return a > b ;
}

int main() {
	int n, m ;
	cin >> n >> m ;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
	}
	sort(a, a + n);
	for (int i = 0 ; i < n - 1 ; i++) {
		d[i] = a[i + 1] - a[i] - 1 ;
	}
	sort(d, d + n, cmp);
	int length = a[n - 1] - a[0] + 1 ;
	cout << length << endl;
	for (int i = 0; i < m - 1; i++) {
		length = length - d[i];
	}
	cout << length << endl;
	return 0 ;
}