#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int fa[N], dep[N];
int n, v, e, firstL = 1; // 第一行输出的标志
int edgeN = 0, total = 0, vN = 0; // 分别表示 边数量，总权值，特殊点边数量
struct Bnode {
    int u, v, c;
};
Bnode road[N];
void init() { // 初始化
    for (int i = 0; i < N; i++) fa[i] = i, dep[i] = 1;
    memset(road, NULL, sizeof road);
    edgeN = 0, total = 0, vN = 0;
}
void quick_sort(int l, int r) { // 快速排序
    if (l >= r) return;
    int x = road[l + r  >> 1].c, i = l - 1, j = r + 1;
    while (i < j) {
        do {i++;} while (road[i].c < x);
        do {j--;} while (road[j].c > x);
        if (i < j) swap(road[i], road[j]);
    }
    quick_sort(l, j), quick_sort(j + 1, r);
}
int find(int x) { // 并查集查询
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void merge(int i, int j) { // 并查集合并
    int x = find(i), y = find(j);
    if (dep[x] <= dep[y]) fa[x] = y;
    else fa[y] = x;
    if (dep[x] == dep[y]) dep[y]++;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> v >> e) {
        init();
        for (int i = 0; i < e; i++) cin >> road[i].u >> road[i].v >> road[i].c;
        quick_sort(0, e - 1);
        for (int i = 0; i < e; i++) {
            if (find(road[i].u) == find(road[i].v)) continue;
            if ((road[i].u == v || road[i].v == v) && vN < 2) merge(road[i].u, road[i].v), edgeN++, total += road[i].c, vN++;
            if (road[i].u != v && road[i].v != v) merge(road[i].u, road[i].v), edgeN++, total += road[i].c;
            if (edgeN == n - 1) break;
        }
        firstL == 1 ? (edgeN == n - 1 && vN <= 2) ? printf("%d", total), firstL = 0 : printf("-1"), firstL = 0 : (edgeN == n - 1 && vN <= 2) ? printf("\n%d", total) : printf("\n-1");
    }
    return 0;
}