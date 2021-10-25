#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ma {
	int first, end;
}qwe[220000];
int n, m, a, b, k, ab = 0;
int bi[110000] = {}, bbi[110000], num[110000] = {};
bool cmp(ma x, ma y) {
	return x.first < y.first;
}
void dis(int x) {

}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> qwe[i].first >> qwe[i].end;
		bi[qwe[i].first]++;
		bi[qwe[i].end]++;
		qwe[i + m].first = qwe[i].end;
		qwe[i + m].end = qwe[i].first;
	}
	sort(qwe + 1, qwe + 1 + m + m, cmp);
	for (int i = 1; i <= 2 * m; i++) {
		if (qwe[i].first > ab) {
			ab = qwe[i].first;
			num[ab] = i;
		}
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a;
		int key = 0;
		for (int j = 1; j <= n; j++) {
			bbi[j] = bi[j];
		}
		for (int j = 1; j <= a; j++) {
			cin >> b;
			bbi[b] = 0;
			for (int p = num[b]; qwe[p].first == b; p++) {
				bbi[qwe[p].end]--;
			}
		}
		for (int j = 1; j <= n; j++) {
			if (bbi[j] > 0) {
				cout << "NO" << endl;
				key = 1;
				break;
			}
		}
		if (!key) cout << "YES" << endl;
	}
}
