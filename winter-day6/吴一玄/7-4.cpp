#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 500010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int n, m, a[MAXN], b[MAXN];
ll sum[MAXN];

void add(int pos, ll val)
{
    for(; pos <= n; pos += lowbit(pos))
        sum[pos] += val;
}

ll ask(int pos)
{
    ll val = 0;
    for(; pos; pos -= lowbit(pos))
        val += sum[pos];
    return val;
}

int main()
{
    in(n); ll ans = 0;
    for(int i = 1; i <= n; ++i) in(b[i]), a[i] = b[i];
    sort(b + 1, b + 1 + n);
    m = unique(b + 1, b + 1 + n) - b - 1;
    for(int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    for(int i = n; i; --i)
    {
        ans += ask(a[i] - 1);
        add(a[i], 1);
    }
    cout << ans << "\n";
    return 0;
}