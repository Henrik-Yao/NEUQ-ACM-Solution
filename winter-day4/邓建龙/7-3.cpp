#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, m;
int g[N][N]; // 图
int dist[N]; // 从1到i最短路径
bool sta[N]; // 确定第i点是否是最短路径
int front[N];
int dijkstra(int begin, int stop) {
    memset(dist, 0x3f, sizeof dist);
    dist[begin] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1; // t 是最近刚确定的新的最短路径点
        for (int j = 0; j < n; j++) if (!sta[j] && (t == -1 || dist[j] < dist[t])) t = j;
        sta[t] = true;
        for (int j = 0; j < n; j++) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                front[j] = t;
            }
        }
    }
    if (dist[stop] == 0x3f3f3f3f) return -1;
    return dist[stop];
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    vector<int> vec;
    for (int i = 0; i < n; i++) front[i] = i;
    for (int i = 0; i < m / 2; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    int begin, stop;
    cin >> begin >> stop;
    int ans = dijkstra(begin, stop);
    int x = front[stop]; // 2
    vec.push_back(stop);
    while (x != front[x]) {
        vec.push_back(x);
        x = front[x];
    }
    vec.push_back(x);
    int flag = 1;
    while (!vec.empty()) {
        if (flag == 1) {
            cout << vec.back();
            flag = 0;
        } else cout << "-->" << vec.back();
        vec.pop_back();
    }
    cout << ":" << dist[stop];
    return 0;
}