#include <bits/stdc++.h>
using namespace std;
int ma[205][205];

int main() {
	int n, m;
	while (cin >> n >> m) {
		memset(ma, 0x3f, sizeof(ma));
		for (int i = 0; i < n; i++) {
			int x, k, y;
			cin >> x >> k;
			for (int i = 0; i < k; i++) {
				cin >> y;
				ma[x][y] = 1;   //x->y
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++) {
					if (ma[i][j] == 1)
						break;
					if (ma[i][j] > ma[i][k] + ma[k][j])
						ma[i][j] = ma[i][k] + ma[k][j];
				}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			if (ma[x][y] > 666)
				cout << "connection impossible\n";
			else
				cout << ma[x][y] << endl;
		}
	}
	return 0;
}