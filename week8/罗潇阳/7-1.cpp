#include <bits/stdc++.h>

using namespace std;

int read() {
	int t;
	scanf("%d", &t);
	return t;
}

vector<int> from[30];
int dp[30];

int main() {
	int T = read();
	while (T--) {
		for (int i = 0; i < 30; ++i) from[i].clear();

		int n = read();
		for (int i = 1; i <= n; ++i) {
			int l = read(), r = read();
			from[r].push_back(l);
		}
		for (int i = 0; i < 30; ++i) {
			dp[i] = dp[i - 1];
			for (auto j : from[i]) 
				dp[i] = max(dp[i], dp[j] + 1);
		}
		printf("%d\n", n - dp[29]);
	}
}
