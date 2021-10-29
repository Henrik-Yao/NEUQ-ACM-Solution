#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int> > q;

// 左上顺时针到左
int x0[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int y0[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, k, l;
// 结果
int res[22][22];
// 炸弹位置
int boom[22][22];
// 翻开的点
int visited[22][22];

bool win() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (res[i][j] == -1)
                sum++;
        }
    }
    if (sum == k) {
        return true;
    } else {
        return false;
    }
}

void func(int a, int b) {
    q.push({a, b});
    visited[a][b] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int num = 0;
        for (int i = 0; i < 8; i++) {
            int x2 = x + x0[i];
            int y2 = y + y0[i];
            if (x2 >= 0 && y2 >= 0 && x2 < n && y2 < m && boom[x2][y2] == 1) {
                num++;
            }
        }
        if (num != 0)
            res[x][y] = num;
        else {
            res[x][y] = 0;
            for (int i = 0; i < 8; i++) {
                int x2 = x + x0[i];
                int y2 = y + y0[i];
                if (x2 >= 0 && y2 >= 0 && x2 < n && y2 < m && visited[x2][y2] == 0) {
                    visited[x2][y2] = 1;
                    res[x2][y2] = 0;
                    q.push({x2, y2});
                }
            }
        }
    }
}


int main() {
    cin >> n >> m >> k >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = -1;
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        boom[a][b] = 1;
    }
    for (int i = 0; i < l; i++) {
        int a, b;
        cin >> a >> b;
        if (boom[a][b] == 1) {
            cout << "You lose";
        } else if (visited[a][b] == 1) {
            continue;
        } else {
            func(a, b);
            for (int j = 0; j < n; j++) {
                for (int w = 0; w < m; w++) {
                    cout << res[j][w] << " ";
                }
                cout << endl;
            }
            if (win()) {
                cout << "You win";
            } else {
                cout << endl;
            }
        }
    }
    return (0);
}

