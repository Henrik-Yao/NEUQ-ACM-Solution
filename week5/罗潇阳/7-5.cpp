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

int n, flag;
int v[50010], a[50010];

void dfs(int x);

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  int st;
  scanf("%d", &st);
  ++st;
  dfs(st);
  if (flag)
    puts("True");
  else
    puts("False");
  return 0;
}

void dfs(int x) {
  v[x] = 1;
  if (!a[x]) {
    flag = 1;
    return;
  }
  if (x - a[x] >= 1 && !v[x - a[x]])
    dfs(x - a[x]);
  if (x + a[x] <= n && !v[x + a[x]])
    dfs(x + a[x]);
}
