#include<bits/stdc++.h>
using namespace std;

typedef long double let;
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define repl(i, t) for (int i = fi[t]; i; i = ne[i])

const int LEN = 5e4 + 1;
char s[LEN], c[LEN];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int lens = strlen(s);
	rep(i, 1, n) {
		scanf("%s", c);
		int lenc = strlen(c), res = 0;
		rep(i, 0, lens - 1) {
			bool ok = true;
			rep(j, 0, lenc - 1) {
				if (c[j] != s[i + j]) {
					ok = false;
					break;
				}
			}
			res += ok;
		}
		printf("%d\n", res);
	}
	return 0;	
}
