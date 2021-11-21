#include <bits/stdc++.h>
using namespace std;

typedef long long var;
typedef long double let;
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define per(i, a, b) for (int (i) = (a); (i) >= (b); --(i))
#define repl(i, t) for (int i = fi[t]; i; i = ne[i])

map<string, string> p;
map<string, vector<int>> hs;

vector<int> Hash(string s);

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    string op, ids, tp;
    cin >> op >> ids >> tp;
    if (op == "R") {
      if (p.count(ids)) {
        puts("Repeated!");
        continue;
      }
      p[ids] = tp;
      hs[ids] = Hash(tp);
      puts("Signed!");
    } else {
      if (!p.count(ids)) {
        puts("Failed!");
        continue;
      }
      if (p[ids] == tp) {
        puts("Success!");
        continue;
      }
      if (hs[ids] == Hash(tp))
        puts("Attention!");
      else
        puts("Failed!");
    }
  }
  return 0;
}

vector<int> Hash(string s) {
  for (int i = 0; i < s.size(); ++i)
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i] = s[i] - 'A' + 'a';
  vector<int> num;
  for (int i = 0; i < s.size(); ++i) {
    int x;
    if (s[i] >= '0' && s[i] <= '9')
      x = s[i] - '0';
    else
      x = s[i] - 'a' + 10;
    num.push_back(x);
  }
  for (int i = 0; i < 10; ++i)
    num.push_back(0);
  vector<int> ans;
  int div = s.size() / 4, sum = div * 4, now = 0;
  for (int i = 1; i <= 4; ++i) {
    int len = div;
    if (sum < s.size())
      ++sum, ++len;
    int x = 0;
    for (int j = now; j <= now + len - 1; ++j)
      x += num[j];
    ans.push_back(x % 36);
    now += len;
  }
  return ans;
}
