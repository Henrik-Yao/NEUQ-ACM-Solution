#include <iostream>
#include <queue>
using namespace std;
int m, n;
int vex[2010][2010];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int vi[2010][2010] = {0};
int ans = 0;
void bfs(int row, int col)
{
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int x0 = q.front().first;
        int y0 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = x0 + dx[i], y = y0 + dy[i];
            if (x < 0 || x >= m || y < 0 || y >= n || vi[x][y] == 1 || vex[x][y] == 0) continue;
            vi[x][y] = 1;
            q.push({x, y});
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vex[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vi[i][j] == 1) continue;
            if (vex[i][j] == 1) bfs(i, j), ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

