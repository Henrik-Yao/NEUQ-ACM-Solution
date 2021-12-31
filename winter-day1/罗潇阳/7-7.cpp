#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long var;
const int N = 1000010;

var read() {
	var a = 0, s = 0, c = getchar();
	while (!isdigit(c)) s |= c == '-', c = getchar();
	while (isdigit(c)) a = a * 10 + c - '0', c = getchar();
	return s ? -a : a;
}

int main() {
  string s;
  cin >> s;
  int l = 0, r = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(')
      l = i;
    if (s[i] == ')')
      r = i;
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'A')
      cout << "sae";
    else if (s[i] == 'B')
      cout << "tsaedsae";
    else if (s[i] == '(') {
      cout << s[i + 1];
      for (int j = r - 1; j >= l + 2; --j) {
        cout << s[j];
        cout << s[i + 1];
      }
      i = r;
    } else if (s[i] == '#')
      return 0;
  }
  return 0;
}
