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

int n, m, q;
vector< pair<int, int> > G[MAXN];
set<int> H[MAXN];

int main()
{
    in(n, m);
    for(int i = 1; i <= m; ++i)
    {
        int u, v, w;
        in(u, v, w);
        G[u].push_back(make_pair(v, w));
    }
    for(int i = 0; i < n; ++i) sort(G[i].begin(), G[i].end());
    in(q);
    while(q--)
    {
        int u, v;
        in(u, v);
        H[u].insert(v);
    }
    for(int i = 0; i < n; ++i)
    {
        int flag = 0;
        for(int j = 0; j < G[i].size(); ++j)
            if(!H[i].count(G[i][j].first)) flag = 1;
        if(!flag) continue;
        cout << i << ":";
        for(int j = 0; j < G[i].size(); ++j)
        {
            if(H[i].count(G[i][j].first)) continue;
            cout << "(" << i << ",";
            cout << G[i][j].first << "," << G[i][j].second << ")";
        }
        cout << "\n";
    }
    return 0;
}