#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int N = 1000010;

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

char s[N];
int n;

void solve() {
  cin >> s + 1;
  n = strlen(s + 1);
  for (int i = 1; i <= n / 2; ++i) {
    if (s[i] != s[n - i + 1]) {
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
