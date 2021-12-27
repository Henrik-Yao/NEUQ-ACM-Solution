#include <bits/stdc++.h>
using namespace std;

bool vld;
int len, height;
string s1, s2, Ans;

void dfs(int l1, int r1, int l2, int r2, int dep) {
	if (l1 > r1) return;
	if (l1 == r1) {
		if (l1 == r1) vld &= (s1[l1] == s2[l2]);
		Ans = Ans + s1[l1];
		return;
	}
	//printf("(%d,%d) (%d,%d)\n", l1, r1, l2, r2);
	//for (int i = l1; i <= r1; ++i) putchar(s1[i]); puts("");
	//for (int i = l2; i <= r2; ++i) putchar(s2[i]); puts("");
	//puts("--------------");
	if (!vld) return;
	if (dep > height) height = dep;
	Ans = Ans + s1[r1];
	int pos = l2 - 1;
	for (int i = l2; i <= r2; ++i) {
		if (s2[i] == s1[r1]) {
			pos = i;
			break;
		}
	}
	if (pos == l2 - 1) return (void)(vld = 0);
	dfs(l1, l1 + (pos - l2) - 1, l2, pos - 1, dep + 1);
	if (!vld) return;
	dfs(l1 + (pos - l2), r1 - 1, pos + 1, r2, dep + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif ONLINE_JUDGE
	while (getline(cin, s1)) {
		getline(cin, s2);
		len = s1.length();
		if (len != s2.length()) {
			puts("INVALID");
			continue;
		}
		Ans = "", vld = 1, height = 1;
		dfs(0, len - 1, 0, len - 1, 1);
		if (vld) cout << height << "\n" << Ans << "\n";
		else puts("INVALID");
	}
	return 0;
}
