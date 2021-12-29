#include <bits/stdc++.h>
using namespace std;

char c;
string s[505];
map <char, int> f;
int N, T, x, cnt, Ans;

struct node { char ch; int w, ls, rs; } a[505];
struct cmp
{
	bool operator() (int x, int y) {
		return a[x].w > a[y].w;
	}
};
//inline bool cmp(int x, int y) { return a[x].w < a[y].w; }
priority_queue < int, vector<int>, cmp > Q;

void dfs(int x, int dep) {
	//printf("%d\n", a[x].w);
	if (a[x].ch != '\0') Ans += dep * a[x].w;
	if (a[x].ls != 0) dfs(a[x].ls, dep + 1);
	if (a[x].rs != 0) dfs(a[x].rs, dep + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif 
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> c >> x;
		f[c] = x;
		a[++cnt] = { c,x,0,0 };
		Q.push(cnt);
	}
	while (Q.size() > 1) {
		int x = Q.top(); Q.pop();
		int y = Q.top(); Q.pop();
		//printf("%d %d\n", a[x].w, a[y].w);
		a[++cnt].w = a[x].w + a[y].w;
		a[cnt].ch = '\0';
		a[cnt].ls = x, a[cnt].rs = y;
		Q.push(cnt);
	}
	dfs(Q.top(), 0);

	for (cin >> T; T--; ) {
		int Sum = 0;
		for (int i = 1; i <= N; ++i) {
			cin >> c >> s[i];
			Sum += f[c] * s[i].length();
		}
		if (Sum > Ans) { puts("No"); continue; }
		sort(s + 1, s + 1 + N);
		bool flg = 1;
		for (int i = 1; i < N; ++i) {
			if (s[i + 1].find(s[i]) == 0) {
				flg = 0; break;
			}
		}
		puts(flg ? "Yes" : "No");
	}
	return 0;
}
