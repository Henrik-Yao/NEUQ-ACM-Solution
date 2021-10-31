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

int n;
char s[4][100];

void dfs(int n, int from, int to);

int main() {
	n = read();
	for (int i = 1; i <= 3; ++i) scanf("%s", s[i]);
	dfs(n, 1, 3);
	return 0;
}

void dfs(int n, int from, int to) {
	if (!n) return ;
	int mid = 0;
	for (int i = 1; i <= 3; ++i) {
		if (i != from && i != to) mid = i;
	}
	dfs(n - 1, from, mid);
	printf("%s->%s\n", s[from], s[to]);
	dfs(n - 1, mid, to);
}
