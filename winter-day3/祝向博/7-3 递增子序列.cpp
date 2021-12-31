#include <bits/stdc++.h>
using namespace std;
inline int read() {
	int ret = 0, f = 1; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -f;
	for (; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - 48;
	return ret * f;
}
int N, a[105];
map <string, int> mp;

void dfs(int pos, int lst, string s, int len) {
	if (len >= 2) mp[s] = 1;
	for (int i = pos; i <= N; ++i)
		if (a[i] >= lst)
			dfs(i + 1, a[i], s + char(a[i]), len + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif
	N = read();
	for (int i = 1; i <= N; ++i) a[i] = read() + 1;
//     for (int i = 1; i <= N; ++i) {
//         if (a[i]<0) puts("fuck");
//     }
	dfs(1, -0x3f3f3f3f, "", 0);
	printf("%d\n", mp.size());
	return 0;
}
