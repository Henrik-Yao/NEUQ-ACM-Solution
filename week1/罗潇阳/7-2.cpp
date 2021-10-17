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

const int N = 1e6 + 1;

int v[N];
int fhave[N], bhave[N];

int main() {
	int n = read();
	int fnum = 0, bnum = 0;
	rep(i, 1, n) {
		bnum += !(bhave[v[i] = read()]++);
	}
	int res = bnum;
	rep(i, 1, n) {
		fnum += !(fhave[v[i]]++);
		bnum -= !(--bhave[v[i]]);
		res = max(res, fnum + bnum);
	}
	printf("%d\n", res);
	return 0;
}
