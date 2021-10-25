#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, a, b, k, cs[10010];
vector<int> v[10010];//创造一个新的容器

// 判断是否每个城市都已经孤立
// 如果全部孤立 返回true
//v[i].size()向量大小:
bool t1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            // 孤立的城市 = 没被摧毁 且 没有连接的城市
            if (cs[i] == 0 && cs[v[i][j]] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        v[a].push_back(b); //尾部插入数字b：
        v[b].push_back(a);//尾部插入数字a：
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        // cs[i] == 1 表示i号城市已被摧毁
        memset(cs, 0, sizeof(cs));
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            cs[a] = 1; // 摧毁标记
        }
        if (t1(n) == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;

}