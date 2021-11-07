#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ma = 3, a[41]{};

void ans() {
	if (a[m] != 0) {
		cout << a[m] << endl;
	}
	else {
		for (int i = ma + 1; i <= m; i++) {
			a[i] = a[i - 1] + a[i - 2];
		}
		ma = m;
		cout << a[m] << endl;
	}
}

int main() {
	a[1] = 0;
	a[2] = 1;
	a[3] = 2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		ans();
	}
}