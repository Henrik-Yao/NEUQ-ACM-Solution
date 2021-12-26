#include <bits/stdc++.h>
using namespace std;

int stk[1000005];

bool Find(string s) {
	int len = s.length();
	int top = 0;
	for (int i=0; i<len; ++i)
		switch (s[i]) {
			case '(': stk[++top] = 1; break;
			case '[': stk[++top] = 2; break;
			case '{': stk[++top] = 3; break;
			case ')': {
				if (stk[top] == 1) --top;
				else return 0;
				break;
			}
			case ']': {
				if (stk[top] == 2) --top;
				else return 0;
				break;
			}
			case '}': {
				if (stk[top] == 3) --top;
				else return 0;
				break;
			}
		}
    if (top>0) return 0;
	return 1;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif // !ONLINE_JUDGE
	string s;
	getline(cin, s);
	printf(Find(s) ? "yes" : "no");
	return 0;
}
