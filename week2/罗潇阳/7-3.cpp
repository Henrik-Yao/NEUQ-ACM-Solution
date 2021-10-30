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

const int N = 1e5 + 100;

int a[N], b[N], c[N], tmp[N];

void merge(int l, int r);

int main() {
	int n = read();
	rep(i, 1, n) a[i] = read();
	merge(1, n);
	rep(i, 1, n) printf("%d ", a[i]);
	return 0;
}

void merge(int l, int r) {
	if (l == r) return ;
	int mid = (l + r) >> 1;
	merge(l, mid), merge(mid + 1, r);
	int tl = 0, tr =0;
	rep(i, l, mid) b[++tl] = a[i];
	rep(i, mid + 1, r) c[++tr] = a[i];
	int cl = 1, cr = 1;
	rep(i, 1, tl + tr) {
		if (cl > tl) tmp[i] = c[cr++];
		else if (cr > tr) tmp[i] = b[cl++];
		else if (b[cl] <= c[cr]) tmp[i] = b[cl++];
		else tmp[i] = c[cr++];
	}
	rep(i, l, r) a[i] = tmp[i - l + 1];
}
