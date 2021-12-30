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

const int N = 110;

int n;
pair<int, string> a[N];

int main() {
	n = read();
  for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		int v = read();
		a[i] = make_pair(v, s);
	}
  sort(a + 1, a + 1 + n, [=] (const pair<int, string> a, const pair<int, string> b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	});
  for (int i = 1; i <= n; ++i)
    cout << a[i].second << " " << a[i].first << "\n";
  return 0;
}
