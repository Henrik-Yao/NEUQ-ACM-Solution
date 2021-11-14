/*#include<iostream>
using namespace std;

bool num[10000001] = { false };
int prime[10000001] = { 0 };

int main() {
	int n, pos = 2, ans = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (!num[i]) prime[pos++] = i;
		for (int j = 2; j < pos && i * prime[j] <= n; j++) {
			num[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (!num[i]) ans++;
	}
	cout << ans;
}*/