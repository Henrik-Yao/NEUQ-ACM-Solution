#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 10010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int fa[MAXN];

int get(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

int main()
{
    int n, m, q;
    in(n, m, q);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    while(m--)
    {
        int x, y;
        in(x, y);
        fa[get(x)] = get(y);
    }
    while(q--)
    {
        int x, y;
        in(x, y);
        if(get(x) == get(y)) puts("In the same gang.");
        else puts("In different gangs.");
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        if(get(i) == i) ++ans;
    cout << ans << "\n";
    return 0;
}