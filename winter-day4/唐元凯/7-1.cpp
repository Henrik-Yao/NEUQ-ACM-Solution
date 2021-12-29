#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5, INF = 1e6;
int w[maxn][maxn]/*城市网*/, v[maxn]/*临时标记是否查询过*/, d[maxn]/*到节点i的路径*/,len[maxn];
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
    for (int i = 0; i < n; i++) {
        len[k] += d[i];
    }
}

int main() {
    int e,x,y;
    while (cin >> n >> e) {
        memset(w, INF, sizeof(w));
        memset(len, 0, sizeof(len));
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            cin >> w[x][y];
            w[y][x] = w[x][y];
        }
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            Dijkstra(i);
            if (len[i] < len[pos])pos = i;
        }
        cout << pos << endl;
    }
}