#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int m, n, a[1001];

int get_deep(int n) {
	if (a[n] == 0)
		return 0;
	int x = get_deep(2 * n);
	int y = get_deep(2 * n + 1);
	return max(x, y) + 1;
}

void get_mid(int n) {
	if (a[n] == 0)
		return ;
	get_mid(2 * n);
	v.push_back(a[n]);
	get_mid(2 * n + 1);
}

int main() {
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> n;
		v.clear();
		memset(a, 0, sizeof(a));
		for (int j = 1; j <= n; j++)
			cin >> a[j];
		get_mid(1);
		for (int j = 0; j < v.size(); j++) {
			cout << v[j];
			if (j != v.size() - 1)
				cout << " ";
		}
		cout << endl << get_deep(1) << endl;
	}
	return 0;
}