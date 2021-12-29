#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 1e9;
int d[N][N]; // d[i][j] 表示从 i 到 j 最短路代价
int n, e;
// floyd 算法
void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
// 求和
int sum(int idx) { // 节点 idx 所有可连通节点代价之和
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (d[idx][i] < INF / 2 && d[idx][i] > 0) total += d[idx][i];
    }
    return total;
}
int main()
{
    while (cin >> n >> e) {
        // 初始化
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = INF;
            }
        }
        // 读入数据
        for (int i = 0; i < e; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            d[a][b] = min(d[a][b], c);
            d[b][a] = min(d[b][a], c);
        }
        // floyd
        floyd();
        int idx;
        int minN = 2147483647; // 用于计算节点可连通代价之和最小值
        // 求最小值并记录对应的节点 idx
        for (int i = 0; i < n; i++) {
            int numm = sum(i);
            if (numm < minN) minN = numm, idx = i;
        }
        cout << idx << endl;
    }
    return 0;
}