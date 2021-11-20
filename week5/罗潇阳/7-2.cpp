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

bool Check(int n);

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
      puts("2");
      continue;
    }
    if (Check(n)) {
      puts("1");
      continue;
    }
    if (Check(n - 2)) {
      puts("2");
      continue;
    }
    puts("3");
  }
  return 0;
}

bool Check(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0)
      return 0;
  return 1;
}
