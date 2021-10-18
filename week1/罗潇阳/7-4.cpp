#include<bits/stdc++.h>
using namespace std;

typedef long long var;
typedef long double let;
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define repl(i, t) for (int i = fi[t]; i; i = ne[i])

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

const int N = 1e3 + 1;

int dp[N][N];

int main() {
	int n = read();
	dp[1][n] = 1;
	var res = 1;
	rep(i, 2, n) {
		var thave = 0;
		rep(j, 1, n) {
			rep(k, 2, n) {
				if (j * k > n) break;
				dp[i][j] += dp[i - 1][j * k];
			}
			thave += dp[i][j];
		}
		res += thave;
		if (!thave) break;
	}
	printf("%lld\n", res);
	return 0;
}
