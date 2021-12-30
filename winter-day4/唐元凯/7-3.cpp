#include<iostream>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

const int maxn = 2000 + 5, INF = 1e6;
int w[maxn][maxn]/*路由网*/, v[maxn]/*临时标记是否查询过*/, d[maxn]/*到节点i的路径*/,fa[maxn]/*父节点信息*/;
int n;

void Dijkstra(int k) {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) d[i] = (i == k ? 0 : INF);
    for (int i = 0; i < n; i++) {
        int x, m = INF;
        for (int y = 0; y < n; y++) if (!v[y] && d[y] <= m) m = d[x = y];
        v[x] = 1;
        for (int y = 0; y < n; y++)
            if (d[y] > d[x] + w[x][y]) {
                d[y] = d[x] + w[x][y];
                fa[y] = x;
            }
    }
}

int main() {
    int e, x, y;
    cin >> n >> e;
    memset(w, INF, sizeof(w));
    for (int i = 0; i < e; i++)
    {
        cin >> x;
        cin >> y;
        cin >> w[x][y];
        w[y][x] = w[x][y];
        ++i;
    }
    cin >> x >> y;
    if (x == y)cout << x << "-->" << y << ":" << 0;
    else {
        Dijkstra(x);
        stack<int>ans;
        int i = y;
        while (fa[i] != x) {
            ans.push(fa[i]);
            i = fa[i];
        }
        cout << x;
        while (!ans.empty()) {
            cout << "-->" << ans.top();
            ans.pop();
        }
        cout << "-->" << y;
        cout << ":" << d[y];
    }
}