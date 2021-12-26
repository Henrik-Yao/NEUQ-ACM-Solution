#include <bits/stdc++.h>
using namespace std;

string s;

bool Find(string s) {
	int len = s.length();
	for (int i=0; i<len; ++i) {
		if (s[i] != s[len - i - 1]) return 0;
	}
	return 1;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif // !ONLINE_JUDGE
	cin >> s;
	printf(Find(s) ? "yes" : "no");
	return 0;
}
