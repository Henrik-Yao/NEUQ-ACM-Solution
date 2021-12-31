#include <bits/stdc++.h>
using namespace std;
int n, e;
int edgeN = 0; // 边数量
int total = 0; // 权值总和
int sign[1510];

struct Bnode {
    int u;
    int v;
    int c;
};
Bnode road[1510];
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
int findRoot(int a) {
    return sign[a] == a ? a : (sign[a] = findRoot(sign[a]));
}
void merge(int a, int b)
{
    int x = findRoot(a), y = findRoot(b); // 分别是两点的根节点特征值
    sign[y] = x;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> e) {
        // 状态初始化
        memset(sign, 0, sizeof sign);
        memset(road, NULL, sizeof road);
        total = 0; edgeN = 0;
        for (int i = 1; i <= n; i++) sign[i] = i; // 特征值
        for (int i = 0; i < e; i++) {
            cin >> road[i].u >> road[i].v >> road[i].c;
        }
        quick_sort(0, e - 1);
        for (int i = 0; i < e; i++) {
            if (findRoot(road[i].u) == findRoot(road[i].v)) continue;
            merge(road[i].u, road[i].v); edgeN++; total += road[i].c;
            if (edgeN == n - 1) break;
        }
        int rootN = 1;
        int root = findRoot(1);
        for (int i = 1; i <= n; i++)if (findRoot(i) != root) rootN++;
        if (rootN > 1) cout << "There is no minimum spanning tree." << endl;
        else {
            cout << total << endl;
        }
    }
    return 0;
}