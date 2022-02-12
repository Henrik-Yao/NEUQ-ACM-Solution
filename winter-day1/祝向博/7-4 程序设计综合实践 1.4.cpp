#include <bits/stdc++.h>
using namespace std;

int N,odd = -1,eve = -1;
int a[1000005];

signed main() {
#ifndef ONLINE_JUDGE
	freopen("prob.in", "r", stdin);
#endif // !ONLINE_JUDGE
	while (~scanf("%d", &a[++N])); --N;
	sort(a + 1, a + 1 + N);
	for (int i = 1; i < N; ++i) printf("%d->", a[i]); printf("%d\n", a[N]);
	for (int i = N; i; --i) {
		if (a[i] % 2 == 1 && odd == -1) odd = i;
		if (a[i] % 2 == 0 && eve == -1) eve = i;
		if (eve != -1 && odd != -1) break;
	}
	for (int i=1; i<=N; ++i)
		if (a[i] % 2 == 1) {
			if (i != odd) printf("%d->", a[i]);
			else printf("%d\n", a[i]);
		}
    if (odd == -1) puts("");
	for (int i=1; i<=N; ++i)
		if (a[i] % 2 == 0) {
			if (i != eve) printf("%d->", a[i]);
			else printf("%d", a[i]);
		}
	return 0;
}
