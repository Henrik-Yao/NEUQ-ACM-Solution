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
vector<int> ans;

int rebuild(int post[], int mid[], int len)
{
    if(!len) return 0;
    int o = ++cnt;
    t[o].val = post[len - 1];
    int i;
    for(i = 0; i < len; ++i)
        if(mid[i] == t[o].val) break;
    if(i == len)
    {
        ok = 0;
        return -1;
    }
    ans.push_back(t[o].val);
    t[o].ls = rebuild(post, mid, i);
    t[o].rs = rebuild(post + i, mid + i + 1, len - i - 1);
    return o;
}

int get(int o)
{
    if(!o) return 0;
    return max(get(t[o].ls), get(t[o].rs)) + 1;
}

int main()
{
    int n; in(n);
    int post[MAXN], mid[MAXN];
    for(int i = 0; i < n; ++i) in(post[i]);
    for(int i = 0; i < n; ++i) in(mid[i]);
    cnt = 0, ok = 1;
    memset(t, 0, sizeof(t));
    ans.clear();
    int rt = rebuild(post, mid, n);
    for(auto x: ans) cout << x << " ";
    return 0;
}