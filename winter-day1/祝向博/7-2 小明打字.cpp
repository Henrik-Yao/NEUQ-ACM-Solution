#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;

string s;

struct node {
	char ch = 0;
	int lst,nxt;
} a[maxn];
bool ins = 0;
int pos, cnt = 2;

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif // !ONLINE_JUDGE
	getline(cin, s);
	a[0].nxt = a[1].lst = pos = 2;
	a[2].nxt = 1;
	for (int i = 0, len = s.length(); i < len; ++i) {
		switch (s[i]) {
			case '[': pos = a[0].nxt; break;
			case ']': pos = 2; break;
			case '{': {
				if (a[pos].lst != 0) pos = a[pos].lst;
				break;
			}
			case '}': {
				if (a[pos].nxt != 1) pos = a[pos].nxt;
				break;
			}
			case '-': ins ^= 1; break;
			case '=': {
				if (a[pos].lst != 0) {
					a[a[a[pos].lst].lst].nxt = pos;
					a[pos].lst = a[a[pos].lst].lst;
				}
				break;
			}
			default: {
				if (!ins || a[pos].nxt == 2) {
					a[++cnt].ch = s[i];
					a[cnt].nxt = pos;
					a[cnt].lst = a[pos].lst;

					a[a[pos].lst].nxt = cnt;
					a[pos].lst = cnt;
				}
				else a[pos].ch = s[i], pos = a[pos].nxt;
				break;
			}

		}
	}
	for (int i = a[0].nxt; i != 2; i = a[i].nxt) putchar(a[i].ch);
	return 0;
}
