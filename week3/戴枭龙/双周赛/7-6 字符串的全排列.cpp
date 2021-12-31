#include <bits/stdc++.h>
using namespace std;
string a;
int v[8];
char b[8];
string t[8];
int n, k;

void dps(int x) {
	if (x == n) {
		for (int i = 0; i < n ; i++) {
			cout << t[i];
		}
		cout << endl;
	} else {
		for (int j = 0; j < n; j++) {
			if (v[j] == 0) {
				v[j] = 1;
				t[x] = b[j];
				dps(x + 1);
				v[j] = 0;
			}
		}
	}
}

int main() {
	cin >> a;
	n = a.length();
	for (int j = 0; j < n; j++) {
		b[j] = a[j];
	}
	sort(b, b + n);
	dps(0);
	return 0;
}
