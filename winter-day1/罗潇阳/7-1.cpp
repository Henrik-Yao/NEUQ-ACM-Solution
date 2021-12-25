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

int n, q;
var sum[N];

void add(int t, var val) {
  for (int i = t; i <= n; i += lowbit(i))
    sum[i] += val;
}

var ask(int t) {
  var val = 0;
  for (int i = t; i; i -= lowbit(i))
    val += sum[i];
  return val;
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    var x;
    scanf("%lld", &x);
    add(i, x);
  }
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int pos;
      var val;
      scanf("%d %lld", &pos, &val);
      add(pos, val);
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%lld\n", ask(r) - ask(l - 1));
    }
  }
  return 0;
}
