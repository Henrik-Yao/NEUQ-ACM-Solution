#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 200 + 5, INF = 1e6;
int w[maxn][maxn]/*路由网*/, v[maxn]/*临时标记是否查询过*/, d[maxn]/*到节点i的路径*/;
int n;

void Dijkstra(int k) {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) d[i] = (i == k ? 0 : INF);
    for (int i = 0; i < n; i++) {
        int x, m = INF;
        for (int y = 0; y < n; y++) if (!v[y] && d[y] <= m) m = d[x = y];
        v[x] = 1;
        for (int y = 0; y < n; y++) d[y] = min(d[y], d[x] + w[x][y]);
    }
}

int main() {
    int e, x, y, cnt;
    while (cin >> n >> e) {
        memset(w, INF, sizeof(w));
        for (int i = 0; i < n; i++)
        {
            cin >> x >> cnt;
            for (int j = 0; j < cnt; j++)
            {
                cin >> y;
                w[x][y] = 1;
            }
        }
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            Dijkstra(x);
            if (d[y] >=INF)cout << "connection impossible" << endl;
            else cout << d[y] << endl;
        }
    }
}