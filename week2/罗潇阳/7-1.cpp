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

char s[3][20];

void dfs(int x, int y, int n);

int main() {
	int n = read();
	scanf("%s%s%s", s[0], s[1], s[2]);
	dfs(0, 2, n);
	return 0;
}

void dfs(int x, int y, int n) {
	if (!n) return ;
	int t = 0;
	rep(i, 0, 2) {
		if (i != x && i != y) t = i;
	}
	dfs(x, t, n - 1);
	printf("%s->%s\n", s[x], s[y]);
	dfs(t, y, n - 1);
}
