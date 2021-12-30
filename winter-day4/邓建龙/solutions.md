# day4

## 7-1 双十一

> **floyd 算法**，三层循环即可 `d[i][j]` 表示从 i 到 j 最短路
>
> 求和时注意判断值，如下

```c++
int sum(int idx) { // 节点 idx 所有可连通节点代价之和
    int total = 0;
    for (int i = 0; i < n; i++) {
        // 使用自定义的最大值 INF 的一半，小于这个值，而不是等于，因为在floyd算法中会更改这些值
        if (d[idx][i] < INF / 2 && d[idx][i] > 0) total += d[idx][i];
    }
    return total;
}
```

## 7-2 路由器

> **floyd算法**
>
> 同 7 - 1

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 1e9;
int d[N][N];
int n, m;
void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
int main()
{
    while (cin >> n >> m) {
        // 初始化
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = INF;
            }
        }
        // 读入数据
        for (int i = 0; i < n; i++) {
            int head, num;
            scanf("%d %d", &head, &num);
            for (int i = 0; i < num; i++) {
                int x;
                scanf("%d", &x);
                d[head][x] = 1;
            }
        }
        // floyd
        floyd();
        while (m--) {
            int l, r;
            scanf("%d%d", &l, &r);
            if (d[l][r] > INF / 2) cout << "connection impossible" << endl;
            else cout << d[l][r] << endl;
        }
    }
    return 0;
}
```

## 7-3 最短路径之Dijkstra

> **Dijkstra算法**
>
> 算法讲解相关文章：https://blog.csdn.net/qq_35644234/article/details/60870719
>
> 这里我开了一个数组 `front`，在将一个点的最短路更新时，记录它前面一个点

```c++
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
                front[j] = t; // 这里便是记录最短路时同时记录前面一个点
            }
        }
    }
    if (dist[stop] == 0x3f3f3f3f) return -1;
    return dist[stop];
}
```

## 7-4 最短路径之Floyd

> **floyd算法**
>
> 这里我用的是 Dijkstra 算法，基本与 7-3 一致

```c++
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
```

## 7-5 迷宫变种-最短路径

> 可以使用 **Dijkstra算法**
>
> 这里可以将二维矩阵转化成 N * M 个点，当作 `Dijkstra` 题目来写
>
> 10 行 10 列  第三行第三列的点可以表示为 (3 - 1) * 10 + 3 - 1

```c++
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
```

## 7-6 森森旅游

> 双向使用 `Dijkstra` 算法，使用 `multiset` 维护，获取每一次查询之后的最小值

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PII;
const int N = 100010, M = 200010 * 2;
const LL INF = 0x3f3f3f3f3f3f3f3fll;
int n, m, Q;
int h1[N], h2[N], e[M], w[M], ne[M], idx;
LL dist1[N], dist2[N];
bool st[N];
int ratio1[N];
// 添加一条边 a->b边权为c
void add(int h[], int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dijkstra(int h[], LL dist[], int start) {
    memset(dist, 0x3f, sizeof dist1);
    memset(st, false, sizeof st);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> Q;
    memset(h1, -1, sizeof h1);
    memset(h2, -1, sizeof h2);
    while (m--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        add(h1, a, b, c), add(h2, b, a, d);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &ratio1[i]);
    dijkstra(h1, dist1, 1);
    dijkstra(h2, dist2, n);
    multiset<LL> S;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] != INF && dist2[i] != INF) {
            S.insert(dist1[i] + (dist2[i] + ratio1[i] - 1) / ratio1[i]);
        }
    }
    while (Q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (dist1[a] != INF && dist2[a] != INF) {
            S.erase(S.find(dist1[a] + (dist2[a] + ratio1[a] - 1) / ratio1[a]));
            ratio1[a] = b;
            S.insert(dist1[a] + (dist2[a] + ratio1[a] - 1) / ratio1[a]);
        }
        printf("%lld\n", *S.begin());
    }
    return 0;
}
```

