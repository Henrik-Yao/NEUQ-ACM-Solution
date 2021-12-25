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

int n, m;
map<string, string> H;

int main() {
  string a, b;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    string a, b;
    cin >> a >> b;
    H[b] = a;
  }
  while (m--) {
    string s;
    cin >> s;
    if (!H.count(s))
      puts("eh");
    else
      cout << H[s] << "\n";
  }
  return 0;
}
