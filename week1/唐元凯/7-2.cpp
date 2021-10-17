#include<iostream>
#include<cstring>

using namespace std;
int num[1000010];
int vis[1000010];
int l[1000010]; int r[1000010];

int main() {
	int n;
	int sum = 0;
	int maxn = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (vis[num[i]] == 0) {
			l[i] = l[i - 1] + 1;
			vis[num[i]] = 1;
		}
		else l[i] = l[i - 1];
	}
	memset(vis, 0, sizeof(vis));
	for (int i = n; i >= 1; i--) {
		if (vis[num[i]] == 0) {
			r[i] = r[i + 1] + 1;
			vis[num[i]] = 1;
		}
		else r[i] = r[i + 1];
	}
	for (int i = 1; i < n; i++) {
		int s = l[i] + r[i + 1];
		if (s > maxn) maxn = s;
	}
	cout << maxn;
}