#include <bits/stdc++.h>
using namespace std;

int N, len, cnt, pre;
string s;

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif // !ONLINE_JUDGE
	while (getline(cin,s)) {
		len = s.length();
		cnt = 0, pre = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '(') ++cnt;
			else if (cnt == 0) ++pre; else --cnt;
		}
		if (pre == 0 && cnt == 0) puts("Match");
		else {
			printf("%d\n", pre + cnt);
			for (int i = 1; i <= pre; ++i) putchar('(');
			cout << s;
			for (int i = 1; i <= cnt; ++i) putchar(')');
			puts("");
		}
	}
	return 0;
}
