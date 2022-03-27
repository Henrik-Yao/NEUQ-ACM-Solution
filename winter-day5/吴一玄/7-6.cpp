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
    while(cin >> n)
    {
        for(int i = 1; i <= n; ++i) in(a[i]);
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; ++i) cout << a[i] << (i == n ? '\n' : ' ');
        int m; in(m);
        while(m--)
        {
            int x; in(x);
            int y = lower_bound(a + 1, a + 1 + n, x) - a;
            if(a[y] == x) cout << y;
            else cout << "0";
            if(m) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}