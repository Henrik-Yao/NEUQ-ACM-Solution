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