#include <bits/stdc++.h>
using namespace std;
int T, n;
struct times {
	int s;
	int e;
} ;
times t[1000];

bool cmp(times s1, times s2) {
	return s1.e < s2.e;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> t[i].s >> t[i].e;
		}
		int i = 0;
		sort(t + 1, t + n + 1, cmp);
		for (int j = 1; j <=n; j++) {
			if (t[j].s >= t[i].e) {
				i = j;
				cnt++;
			}
		}
		cout << n - cnt << endl;
	}
	return 0;
}