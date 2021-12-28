#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1010;

void ins(){}
template<typename T, typename ...otr_T>
void ins(T &t, otr_T & ...otr)
{
    cin >> t;
    ins(otr...);
}

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, in[MAXN], tmp[MAXN];
vector<int> G[MAXN];

int topsort()
{
    queue<int> q;
    for(int i = 1; i <= n; ++i)
    {
        tmp[i] = in[i];
        if(!in[i]) q.push(i);
    }
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(auto y: G[x])
            if(--in[y] == 0) q.push(y);
    }
    int flag = 1;
    for(int i = 1; i <= n; ++i)
        if(in[i]) flag = 0;
    if(!flag) return 0;
    for(int i = 1; i <= n; ++i) in[i] = tmp[i];
    flag = 0;
    for(int i = 1; i <= n; ++i)
        if(!in[i]) q.push(i), ++flag;
    if(flag > 1) return 2;
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        flag = 0;
        for(auto y: G[x])
        {
            if(--in[y] == 0) q.push(y), ++flag;
        }
        if(flag > 1) return 2;
    }
    return 1;
}

int main()
{
    while(cin >> n >> m)
    {
        memset(in, 0, sizeof(in));
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i)
        {
            int u, v;
            ins(u, v);
            G[u].push_back(v);
            ++in[v];
        }
        cout << topsort() << "\n";
    }
    return 0;
}