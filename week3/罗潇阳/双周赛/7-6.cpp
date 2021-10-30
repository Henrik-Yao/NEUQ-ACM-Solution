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

char s[20];

int main() {
#ifndef ONLINE_JUDGE 
	freopen("main.in", "r", stdin);
	freopen("main.out", "w", stdout);
#endif
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	sort(s + 1, s + 1 + n);
	do {
		puts(s + 1);
	} while (next_permutation(s + 1, s + 1 + n));
	return 0;
}

