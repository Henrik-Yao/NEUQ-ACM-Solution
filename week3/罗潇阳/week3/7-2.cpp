#include <bits/stdc++.h>
using namespace std;

typedef long long var;
typedef long double let;
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define repl(i, t) for (int i = fi[t]; i; i = ne[i])

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

int n, m;
int f[510], v[510];
vector<int> G[510];

int dfs(int x) {
    v[x] = 1;
    if(f[x]) return f[x];
    for(auto y: G[x])
        f[x] += dfs(y);
    return f[x];
}

int main() {
	n = read(), m = read();
	while (m--) {
		int u = read(), v = read();
		G[u].push_back(v);
	}
	int s = read(), t = read();
	f[t] = 1;
	printf("%d ", dfs(s));
	int flag = 1;
	rep(i, 1, n) 
		if (!f[i] && v[i]) flag = 0;
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}    
