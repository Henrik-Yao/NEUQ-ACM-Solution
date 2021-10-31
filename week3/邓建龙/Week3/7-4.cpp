#include <iostream>

using namespace std;

const int N = 1002;

bool visited[N][N] = {false};
int res[N][N];
int nums[N][2];
int index = 0;
char vex[N][N];
int x0[4] = {-1, 0, 1, 0};
int y0[4] = {0, 1, 0, -1};
int n, m, total = 0;

void dfs(int a, int b)
{
    visited[a][b] = true;
    total++;
    nums[index][0] = a;
    nums[index][1] = b;
    index++;
    for (int i = 0; i < 4; i++) {
        int x = a + x0[i];
        int y = b + y0[i];
        if (x < 1 || y < 1 || x > n || y > n) continue;
        if (visited[x][y] || vex[a][b] == vex[x][y]) continue;
        dfs(x, y);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> vex[i][j];
        }
    }
    // 超时
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             memset(visited, false, sizeof(visited));
//             dfs(i, j);
//             res[i][j] = total;
//             total = 0;
//         }
//     }
    for (int i = 0; i < m; i++) {
        int fromX, fromY;
        cin >> fromX >> fromY;
        if (visited[fromX][fromY]) {
            i != m - 1 ? cout << res[fromX][fromY] << endl : cout << res[fromX][fromY];
        } else {
            dfs(fromX, fromY);
            for (int p = 0; p < index; p++) {
                res[nums[p][0]][nums[p][1]] = total;
            }
            index = 0;
            total = 0;
            i != m - 1 ? cout << res[fromX][fromY] << endl : cout << res[fromX][fromY];
        }
        // i != m - 1 ? cout << res[fromX][fromY] << endl : cout << res[fromX][fromY];
    }
    return 0;
}