#include <bits/stdc++.h>
using namespace std;
#define maxn 10001
int a[maxn][2];

int main() {
	int n, m, k, p, q;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	cin >> k;
	for (int x = 1; x <= k; x++) {
		int v[maxn] = {0};
		cin >> p;
		for (int i = 0; i < p; i++) {
			cin >> q;
			v[q] = 1;
		}
		bool prime = 1;
		for (int i = 0; i < m; i++) {
			if (v[a[i][0]] == 0 && v[a[i][1]] == 0) {
				prime = 0;
				break;
			}
		}
		if (prime) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}