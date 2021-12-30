#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m;
int g[N][N]; // 图
int dist[N]; // 从1到i最短路径
bool sta[N]; // 确定第i点是否是最短路径
int front[N];
vector<int> vec;
int dijkstra(int begin, int stop) {
    memset(dist, 0x3f, sizeof dist);
    memset(sta, false, sizeof sta);
    for (int i = 0; i < n; i++) front[i] = i;
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
void prin(int begin, int stop)
{
    vec.clear();
    int ans = dijkstra(begin, stop);
        if (ans == -1) {
            printf("%d->%d:-1\n", begin, stop);
        } else {
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
                } else cout << "->" << vec.back();
                vec.pop_back();
            }
            cout << ":" << dist[stop] << endl;
        }
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    int begin, stop;
    for (int i = 0; i < 2; i++) {
        cin >> begin >> stop;
        prin(begin, stop);
    }
    int maxs = begin, maxe = stop;
    int maxN = dijkstra(maxs, maxe);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int maxNN = dijkstra(i, j);
            if (maxNN > maxN) maxs = i, maxe = j, maxN = maxNN;
        }
    }
    prin(maxs, maxe);
    return 0;
}