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

struct Node {
  string name;
  int T, P;
} p[N];

int ans[N];
int n, m, cnta;
map<string, int> H;
int cnt;
int fa[N], vis[N];

void solve() {
	n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    int k = read();
    while (k--) {
      string name;
			cin >> name;
      H[name] = ++cnt;
      fa[H[name]] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
		cin >> p[i].name;
		p[i].T = read(), p[i].P = read();
    p[i].P = min(p[i].P, 60);
  }
  int now = 1;
  var sum = 0;
  int nowtime = 0;
  while (now <= n) {
    while (now <= n && vis[now])
      ++now;
    if (now > n)
      break;
    int f = fa[H[p[now].name]], j = now;
    do {
      if (vis[j] || fa[H[p[j].name]] != f) {
        ++j;
        continue;
      }
      sum += max(0, nowtime - p[j].T);
      ans[++cnta] = j;
      nowtime = max(nowtime, p[j].T) + p[j].P;
      vis[j++] = 1;
    } while (f && j <= n && p[j].T <= nowtime);
  }
  for (int i = 1; i <= n; ++i)
    cout << p[ans[i]].name << "\n";
  printf("%.1f\n", 1.0 * sum / n);
  return;
}

int main() { solve(); }
