#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;

int sum[maxn << 2], add[maxn << 2];
int a[maxn], n;

void PushUp(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void BuildTree(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	BuildTree(l, m, rt << 1);
	BuildTree(m + 1, r, rt << 1 | 1);
	PushUp(rt);
}

void Update(int i, int x, int l, int r, int rt) {
	if (l == r) {
		sum[rt] += x;
		return;
	}
	int m = (l + r) >> 1;
	if (i <= m)Update(i, x, l, m, rt << 1);
	else Update(i, x, m + 1, r, rt << 1 | 1);
	PushUp(rt);
}
/*
void PushDown(int ln,int rn,int rt) {
	if (add[rt]) {
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += add[rt] * ln;
		sum[rt << 1 | 1] += add[rt] * rn;
		add[rt] = 0;
	}
}
*/
long long Query(int L, int R, int l, int r, int rt) {
	//if (L > r || R < l) return 0;
	if (L <= l && r <= R) {
		return sum[rt];
	}
	int m = (l + r) >> 1;
	//PushDown(m - l + 1, r - m, rt);
	long long ans = 0;
	if (L <= m)ans += Query(L, R, l, m, rt << 1);
	if (R > m)ans += Query(L, R, m + 1, r, rt << 1 | 1);
	return ans;
}

int main() {
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	BuildTree(1, n, 1);
	while(q--){
		int ope, il, xr;
		cin >> ope >> il >> xr;
		if (ope == 1) {
			Update(il, xr, 1, n, 1);
		}
		else if (ope == 2) {
			cout << Query(il, xr, 1, n, 1) << endl;
		}
	}
}
///////////////////////
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;

int sum[maxn << 2], add[maxn << 2];
int a[maxn], n, N;

void BuildTree(int n) {
	N = 1; while (N < n + 2) N <<= 1;
	for (int i = 1; i <= n; ++i) sum[N + i] = a[i];
	for (int i = N - 1; i > 0; --i) {
		sum[i] = sum[i << 1] + sum[i << 1 | 1];
		add[i] = 0;
	}
}

void Update(int L, int C) {
	for (int s = N + L; s; s >>= 1) {
		sum[s] += C;
	}
}

int Query(int L, int R) {
	int ans = 0;
	for (int s = N + L - 1, t = N + R + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
		if (~s & 1) ans += sum[s ^ 1];
		if (t & 1) ans += sum[t ^ 1];
	}
	return ans;
}

int main() {
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	BuildTree(n);
	while (q--) {
		int ope, il, xr;
		cin >> ope >> il >> xr;
		if (ope == 1) {
			Update(il, xr);
		}
		else {
			cout << Query(il, xr) << endl;
		}
	}
}