#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

struct Node
{
    int ls, rs;
    int dep, val;
}t[MAXN];

int mx, cnt;
vector<Node> nodes[MAXN];

void build(int &o, int depth)
{
    int x; in(x);
    if(!x) return;
    o = ++cnt;
    t[o].val = x;
    t[o].dep = depth;
    build(t[o].ls, depth + 1);
    build(t[o].rs, depth + 1);
    if(!t[o].ls && !t[o].rs)
    {
        //cout << t[o].val << " " << t[o].dep << endl;
        nodes[depth].push_back(t[o]);
        mx = max(mx, depth);
    }
}

int main()
{
    int rt;
    build(rt, 0);
    int ans = -0x7fffffff, id = 0;
    for(int i = mx; ~i; --i)
    {
        int res = 0;
        if(!nodes[i].size()) continue;
        for(auto x: nodes[i]) res += x.val;
        //cout << res << " " << ans << " " << i << endl;
        if(res > ans)
        {
            ans = res;
            id = i;
        }
    }
    cout << id << endl;
    //cout << ans << " " << id << "\n";
    return 0;
}