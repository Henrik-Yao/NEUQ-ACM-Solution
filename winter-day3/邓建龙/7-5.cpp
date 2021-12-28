#include <bits/stdc++.h>
using namespace std;
int n, m;
int fa[310], dep[310]; // 父节点 深度
int edgeN = 0, maxC = 0;
struct Bnode {
    int u, v, c;
};
Bnode road[10010];
// 快速排序
void quick_sort(int l, int r) {
    if (l >= r) return;
    int x = road[l + r >> 1].c, i = l - 1, j = r + 1;
    while (i < j) {
        do {i++;} while (road[i].c < x);
        do {j--;} while (road[j].c > x);
        if (i < j) swap(road[i], road[j]);
    }
    quick_sort(l, j), quick_sort(j + 1, r);
}
// 并查集查询
int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x])); // 返回父节点值  并且父节点会更新成最顶层
}
// 并查集合并
void merge(int i, int j) {
    int x = find(i), y = find(j);
    if (dep[x] <= dep[y]) fa[x] = y;
    else fa[y] = x;
    if (dep[x] == dep[y] && x != y) dep[y]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i, dep[i] = 1;
    for (int i = 0; i < m; i++) cin >> road[i].u >> road[i].v >> road[i].c;
    quick_sort(0, m - 1); // 快速排序
    for (int i = 0; i < m; i++) {
        if (find(road[i].u) == find(road[i].v)) continue;
        merge(road[i].u, road[i].v), edgeN++, maxC = max(maxC, road[i].c);
    }
    cout << edgeN << " " << maxC;
    return 0;
}