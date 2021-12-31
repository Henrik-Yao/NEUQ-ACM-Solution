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

int n, m;
vector<int> ans[110];

int main() {
	n = read();
  for (int i = 1; i <= n; ++i) {
    int x = read();
    int mn = 0x7fffffff, id = 0;
    for (int j = 1; j <= m; ++j) {
      int v = ans[j][ans[j].size() - 1];
      if (v > x && v < mn) {
        mn = v;
        id = j;
      }
    }
    if (!id) {
      ++m;
      ans[m].push_back(x);
    } else {
      ans[id].push_back(x);
    }
  }
  int id = 0;
  for (int i = 1; i <= m; ++i)
    for (auto j : ans[i])
      if (j == 1)
        id = i;
  cout << ans[id][0];
  for (int i = 1; i < ans[id].size(); ++i)
    cout << " " << ans[id][i];
  cout << "\n";
  cout << m << "\n";
  return 0;
}
