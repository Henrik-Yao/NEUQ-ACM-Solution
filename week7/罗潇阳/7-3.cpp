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


map<char, int> H;

int main() {
  string s;
  while (getline(cin, s)) {
    string o;
    getline(cin, o);
    H.clear();
    for (int i = 0; i < o.size(); ++i) {
      H[o[i]] = 1;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (H[s[i]])
        continue;
      cout << s[i];
    }
    cout << "\n";
  }
  return 0;
}
