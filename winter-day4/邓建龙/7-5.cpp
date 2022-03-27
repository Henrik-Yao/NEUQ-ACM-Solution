#include <bits/stdc++.h>
using namespace std;
const int N = 15;
const int INF = 1e9 + 7;
int vex[N][N];
int m, n;
int g[N * N][N * N];
int dist[N * N];
int sta[N * N];
int front[N * N];
int fx, fy, gx, gy;
int dijkstra(int fromx, int fromy, int gox, int goy) {
    memset(dist, INF, sizeof dist);
    dist[fromx * m + fromy] = 0;
    for (int i = 0; i < n * m; i++) {
        int t = -1;
        for (int j = 0; j < m * n; j++) if (!sta[j] && (t == -1 || dist[j] < dist[t])) t = j;
        sta[t] = true;
        for (int j = 0; j < n * m; j++) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                front[j] = t;
            }
        }
    }
    if (dist[gox * m + goy] > INF / 2) return -1;
    return dist[gox * m + goy];
}
int main()
{
    cin >> m >> n;
    cin >> fx >> fy >> gx >> gy;
    for (int i = 0; i < n * m; i++) front[i] = i;
    memset(vex, INF, sizeof vex);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &vex[i][j]);
        }
    }
    memset(g, INF, sizeof g);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vex[i][j] == -1) continue;
            // 上 i - 1 j
            if (i - 1 >= 0 && vex[i - 1][j] != -1 && vex[i - 1][j] < INF / 2) g[i * m + j][(i - 1) * m + j] = vex[i - 1][j];
            // 右 i j + 1
            if (j + 1 < m && vex[i][j + 1] != -1 && vex[i][j + 1] < INF / 2) g[i * m + j][i * m + j + 1] = vex[i][j + 1];
            // 下 i + 1 j
            if (i + 1 < n && vex[i + 1][j] != -1 && vex[i + 1][j] < INF / 2) g[i * m + j][(i + 1) * m + j] = vex[i + 1][j];
            // 左 i j - 1
            if (j - 1 >= 0 && vex[i][j - 1] != -1 && vex[i][j - 1] < INF / 2) g[i * m + j][i * m + j - 1] = vex[i][j - 1];
        }
    }
    int ans = dijkstra(fx, fy, gx, gy);
    vector<int> res;
    res.push_back(gx * m + gy);
    int x = front[gx * m + gy];
    while (x != front[x]) {
        res.push_back(x);
        x = front[x];
    }
    res.push_back(x);
    int i = 0;
    while (i < res.size()) {
        printf("(%d %d)", res[i] / m, res[i] % m); i++;
    }
    return 0;
}