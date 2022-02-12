#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 110;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

struct Node
{
    int val;
    int ls, rs;
}t[MAXN];
int cnt, ok;
vector<int> ans[MAXN];

int rebuild(int pre[], int mid[], int len)
{
    if(!len) return 0;
    int o = ++cnt;
    t[o].val = pre[1];
    int i;
    for(i = 1; i <= len; ++i)
        if(mid[i] == t[o].val) break;
    t[o].ls = rebuild(pre + 1, mid, i - 1);
    t[o].rs = rebuild(pre + i, mid + i, len - i);
    return o;
}

int get(int o, int d)
{
    if(!o) return 0;
    ans[d].push_back(t[o].val);
    int mx = 0;
    mx = max(mx, get(t[o].ls, d + 1));
    mx = max(mx, get(t[o].rs, d + 1));
    return mx + 1;
}

int main()
{
    int n; in(n);
    int pre[MAXN], mid[MAXN];
    for(int i = 1; i <= n; ++i) in(pre[i]);
    for(int i = 1; i <= n; ++i) in(mid[i]);
    cnt = 0, ok = 1;
    memset(t, 0, sizeof(t));
    int rt = rebuild(pre, mid, n);
    int mx = get(rt, 1);
    for(int i = 1; i <= mx; ++i)
        for(auto x: ans[i]) cout << x << " ";
    return 0;
}