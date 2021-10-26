#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	string* b = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	int h = 0;
	for (int i = 0; i < m; i++) {
		int d, s;
		cin >> d >> s;
		if (a[h] == d) h -= s;
		else h += s;
		if (h < 0) h += n;
		if (h >= n) h -= n;
	}
	cout << b[h];
}