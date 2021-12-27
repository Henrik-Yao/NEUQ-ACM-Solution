#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int len, top;
char tsta[maxn];
string s, sta[maxn];

void display() {
	puts("----------------");
	for (int i = 0; i <= top; ++i) cout << sta[i] << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	getline(cin, s);
	len = s.length();
	for (int i = 0; i < len; ++i) {
		switch (s[i]) {
			case '(': {
				tsta[++top] = s[++i];
				sta[top] = "";
				break;
			}
			case ')': {
				int Length = sta[top].length();
				for (int j = Length - 1; j >= 0; --j) {
					sta[top - 1] = sta[top - 1] + tsta[top] + sta[top][j];
				}
				sta[top - 1] = sta[top - 1] + tsta[top];
				--top;
				break;
			}
			default: {
                if (s[i] != '#') sta[top] += s[i];
				break;
			}
		}
	}
	int Length = sta[0].length();
	for (int i = 0; i < Length; ++i) {
		if (sta[0][i] != 'A' && sta[0][i] != 'B') putchar(sta[0][i]);
		else cout << ((sta[0][i] == 'A') ? "sae" : "tsaedsae");
	}
	return 0;
}
