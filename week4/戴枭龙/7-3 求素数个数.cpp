#include <bits/stdc++.h>
using namespace std;
int prime[10000001];
int vis[10000001];

int main() {
	int n, cnt = 0;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!vis[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = true;

			if (i % prime[j] == 0)
				break;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
