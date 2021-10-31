#include <iostream>

using namespace std;

const int N = 505;

int vec[N][N];
int path[N];
bool visited[N];
int n, m;
int a, b;
int from, to;

int dfs(int from)
{
    visited[from] = true;
    if (path[from]) return path[from];
    for (int i = 1; i <= n; i++) {
        if (vec[from][i] == 1) {
            path[from] += dfs(i);
        }
    }
    return path[from];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a][b] = 1;
    }
    cin >> from >> to;
    path[to] = 1;
    int res = dfs(from);
    int whether = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] && !path[i]) {
            whether = 0;
        }
    }
    if (whether) {
        cout << res << " Yes" << endl;
    } else {
        cout << res << " No" << endl;
    }
    return 0;
}

