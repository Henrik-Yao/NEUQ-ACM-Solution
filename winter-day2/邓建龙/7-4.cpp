#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, q, a1, a2, b1, b2;
set<int> st;
int fa[N], dep[N]; // 分别是存放父节点，秩（子树深度）
// 初始化
void init(int n) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i; dep[i] = 1; // 将每个节点父节点初始化为自己，秩初始化为1
    }
}
// 查询
int find(int x) {
    // 如果fa[x] = x 表示该节点没有父节点
    // fa[x] = find(fa[x]) 表示将该节点父节点更新为父节点的父节点
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
// 合并
void merge(int i, int j) {
    // x 表示 i 节点的父节点
    int x = find(i), y = find(j);
    // 如果 x 节点深度小于 y 节点，将 y 作为 x 节点以缩小总深度
    if (dep[x] <= dep[y]) fa[x] = y;
    else fa[y] = x;
    // 当 x == y 时，两树深度相同，合并时会深度加 1，x == y 满足, x <= y 所以 f[x] = y，即 y 节点是 x 节点父节点
    if (dep[x] == dep[y] && x != y) dep[y]++;
}
int main()
{
    cin >> n >> m >> q;
    init(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a1, &a2);
        merge(a1, a2);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &b1, &b2);
        find(b1) == find(b2) ? printf("In the same gang.\n") : printf("In different gangs.\n");
    }
    for (int i = 1; i <= n; i++) {
        int x = fa[i];
        while (x != fa[x]) {
            x = fa[x];
        }
        st.insert(x);
    }
    cout << st.size() << endl;
    return 0;
}