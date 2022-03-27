#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, string>ys;
	for (int i = 1; i <= n; i++) {
		string p, q;
		cin >> p >> q;
		ys[q] = p;
	}
	for (int i = 1; i <= m; i++) {
		string x;
		cin >> x;
		if (ys.count(x))
			cout << ys[x] << endl;
		else
			cout << "eh" << endl;
	}
	return 0;
}