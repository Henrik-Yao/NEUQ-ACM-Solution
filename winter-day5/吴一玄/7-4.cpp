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

int n, a[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    in(n);
    for(int i = 1; i <= n; ++i) in(a[i]);
    int x, l = 1, r = n, mid = 1, cnt = 0; in(x);
    while(l <= r)
    {
        mid = (l + r) >> 1; ++cnt;
        if(a[mid] == x) break;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    if(a[mid] != x) cout << "-1\n" << cnt << "\n";
    else cout << mid - 1 << "\n" << cnt << "\n";
    return 0;
}