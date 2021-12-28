#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 100010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, fa[MAXN];
struct Edge
{
    int u, v, w;
    bool operator < (const Edge &x) const
    {
        return w < x.w;
    }
}e[MAXN];

inline int get(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

int main()
{
    int num;
    while(cin >> n >> num >> m)
    {
        ++num;
        for(int i = 1; i <= m; ++i) in(e[i].u, e[i].v, e[i].w), ++e[i].u, ++e[i].v;
        for(int i = 1; i <= n; ++i) fa[i] = i;
        sort(e + 1, e + 1 + m);
        int cnt = 0; ll sum = 0;
        int tim = 0;
        for(int i = 1; i <= m; ++i)
        {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if(get(u) == get(v)) continue;
            if(u == num || v == num)
            {
                if(tim >= 2) continue;
                //cout << u << " " << v << endl;
                ++tim;
            }
            sum += w; ++cnt;
            fa[get(u)] = get(v);
        }
        if(cnt == n - 1) cout << sum << "\n";
        else cout << "-1\n";
    }
    return 0;
}