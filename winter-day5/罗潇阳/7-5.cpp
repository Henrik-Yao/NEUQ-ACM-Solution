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

typedef long long ll;
const int MAXN = 500010;

map<string, pair<int, string>> f;

bool Check(string s1, string s2);

int main() {
	int n = read();
  for (int i = 1; i <= n; ++i) {
    string a, b;
		cin >> a >> b;
    if (b[b.size() - 1] == 'f')
      f[a] = make_pair(2, "");
    else if (b[b.size() - 1] == 'm')
      f[a] = make_pair(1, "");
    else if (b[b.size() - 1] == 'n')
      f[a] = make_pair(1, b.substr(0, b.size() - 4));
    else if (b[b.size() - 1] == 'r')
      f[a] = make_pair(2, b.substr(0, b.size() - 7));
  }
  int m = read();
  while (m--) {
    string a, b, c, d;
		cin >> a >> b >> c >> d;
    if (f.find(a) == f.end() || f.find(c) == f.end()) {
      cout << "NA\n";
      continue;
    } else if (f[a].first == f[c].first) {
      cout << "Whatever\n";
      continue;
    } else if (Check(a, c))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}

bool Check(string s1, string s2) {
  int fa = 1;
  for (string sa = s1; !sa.empty(); sa = f[sa].second, fa++) {
    int fb = 1;
    for (string sb = s2; !sb.empty(); sb = f[sb].second, fb++) {
      if (fa >= 5 && fb >= 5)
        return 1;
      if (sa == sb && (fa < 5 || fb < 5)) {
        return 0;
      }
    }
  }
  return 1;
}
