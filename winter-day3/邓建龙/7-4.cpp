#include <bits/stdc++.h>
using namespace std;
int n, m;
int vex[110][110];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool vis[110][110];
int ans = 0;
void init() {
    memset(vis, false, sizeof vis);
}
void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    while (!q.empty()) {
        int x0 = q.front().first, y0 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = x0 + dx[i], y = y0 + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == true || vex[x][y] == 0) continue;
            vis[x][y] = true;
            q.push({x, y});
        }
    }
}
int main()
{
    init();
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vex[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (vex[i][j] == 1) bfs(i, j), ans++;
        }
    }
    cout << ans << endl;
    return 0;
}