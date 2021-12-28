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

void print(int o)
{
    if(!o) return;
    print(t[o].ls);
    print(t[o].rs);
    cout << t[o].val << " ";
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
    print(rt);
    return 0;
}