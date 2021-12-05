#include <bits/stdc++.h>
using namespace std;
int dp[401][20000];

int main() {
	int n, c, v[1500], w[1500];//n物品数量，c背包容量
	while (cin >> n >> c) {

		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= c; j++) {
				if (w[i] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}
		}
		cout << dp[n][c] << endl;
	}
	return 0;
}