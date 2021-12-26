#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1000010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

struct Node
{
    string name;
    int T, P;
}p[MAXN];

int ans[MAXN];
int n, m, cnta;
map<string, int> H; int cnt;
int fa[MAXN], vis[MAXN];

void solve()
{
    in(n, m);
    for(int i = 1; i <= m; ++i)
    {
        int k; in(k);
        while(k--)
        {
            string name; in(name);
            H[name] = ++cnt;
            fa[H[name]] = i;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        in(p[i].name, p[i].T, p[i].P);
        p[i].P = min(p[i].P, 60);
    }
    int now = 1; ll sum = 0; int nowtime = 0;
    while(now <= n)
    {
        while(now <= n && vis[now]) ++now;
        if(now > n) break;
        int f = fa[H[p[now].name]], j = now;
        do
        {
            if(vis[j] || fa[H[p[j].name]] != f)
            {
                ++j; continue;
            }
            sum += max(0, nowtime - p[j].T);
            ans[++cnta] = j;
            nowtime = max(nowtime, p[j].T) + p[j].P;
            vis[j++] = 1;
        }while(f && j <= n && p[j].T <= nowtime);
    }
    for(int i = 1; i <= n; ++i)
        cout << p[ans[i]].name << "\n";
    printf("%.1f\n", 1.0 * sum / n);
    return;
}

int main()
{
    solve();
}