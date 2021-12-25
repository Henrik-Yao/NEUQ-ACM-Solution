#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long var;

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

string s;
int n;

void solve() {
  while (cin >> s) {
    n = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        ++n;
      else {
        if (n)
          --n;
        else
          ++ans;
      }
    }
    if (!(ans + n))
      cout << "Match\n";
    else {
      cout << ans + n << "\n";
      for (int i = 1; i <= ans; ++i)
        cout << "(";
      cout << s;
      for (int i = 1; i <= n; ++i)
        cout << ")";
      cout << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
