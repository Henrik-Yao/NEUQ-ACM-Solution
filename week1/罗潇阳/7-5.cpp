#include<bits/stdc++.h>
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

const int N = 1e5 + 1;

int n, m;
int face[N];
char name[N][20];

int count(int t, int f, int s, int d) {
	if (f ^ d) return (t + s - 1) % n + 1;
	return (t +  n - s - 1) % n + 1;
}

int main() {
	n = read(), m = read();
	rep(i, 1, n) {
		scanf("%d%s", &face[i], name[i]);
	}
	int t = 1;
	rep(i, 1, m) {
		t = count(t, face[t], read(), read());
	}
	printf("%s", name[t]);
	return 0;
}
