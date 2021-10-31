#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull dp[65], f[65];
int main() {
	for (int i = 1; i <= 64; i++)
		dp[i] = f[i] = 2 * f[i - 1] + 1;
	for (int i = 1; i <= 64; i++)
		for (int j = 0; j < i; j++)
			dp[i] = min(dp[i], 2 * dp[j] + f[i - j]);
	int n;
	while (cin >> n)
		cout << dp[n] << endl;
	return 0;
}

