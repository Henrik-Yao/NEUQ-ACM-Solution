#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 500010;
const ll inf = 0x3f3f3f3f3f3f3f3f;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int n, m;
ll a[MAXN];

bool Check(ll mid)
{
    int cnt = 1;
    ll lst = a[1];
    for(int i = 2; i <= n; ++i)
        if(a[i] - lst >= mid) lst = a[i], ++cnt;
    if(cnt >= m) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    in(n, m);
    for(int i = 1; i <= n; ++i) in(a[i]);
    sort(a + 1, a + 1 + n);
    ll l = 1, r = 0x7fffffff, ans;
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        if(Check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}