#include <bits/stdc++.h>

using namespace std;

int read() {
	int t;
	scanf("%d", &t);
	return t;
}

const int N = 1000000;

int main() {
	int n = read();
	int txp = 1, nxp = 0, res = 0;
	for (int i = 1; i <= n; ++i) {
		nxp = max(nxp, i + read());
		if (nxp >= n) {
			res++;
			break;
		}
		if (i == txp) {
			res++;
			txp = nxp;
		}
	}
	printf("%d\n", res);
	return 0;
}
