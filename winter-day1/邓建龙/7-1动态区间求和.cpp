#include <bits/stdc++.h>
#define lowbit(i) ((i)&(-i))
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll n, q, x, c[N];
void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] += v;
}
ll getSum(int x) {
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ans += c[i]; return ans;
}
int main()
{
    // 树状数组
    cin >> n >> q;
    for (int i = 1; i <= n; i++) scanf("%d", &x), update(i, x);
    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) update(l, r);
        else cout << getSum(r) - getSum(l - 1) << endl;
    }
    return 0;
}