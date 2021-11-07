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

int v[10010];

bool check(int x);

int main() {
  for (int i = 2; i <= 10000; ++i)
    v[i] = check(i);
  int a, b;
  while (cin >> a >> b) {
    vector<int> ans;
    for (int i = a; i <= b; ++i)
      if (v[i])
        ans.push_back(i);
    for (int i = 0; i < ans.size(); ++i)
      printf("%d%c", ans[i], i == (ans.size() - 1) ? '\n' : ' ');
  }
  return 0;
}

bool check(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0)
      return 0;
  return 1;
}

