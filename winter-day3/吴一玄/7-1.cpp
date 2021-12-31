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

int n, m;
vector< pair<int, int> > G[MAXN];

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
    for(int i = 0; i < n; ++i)
    {
        if(!G[i].size()) continue;
        cout << i << ":";
        for(int j = 0; j < G[i].size(); ++j)
        {
            cout << "(" << i << ",";
            cout << G[i][j].first << "," << G[i][j].second << ")";
        }
        cout << "\n";
    }
    return 0;
}