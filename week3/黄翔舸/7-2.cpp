#include<iostream>
using namespace std;

int sou[510], path[510], vec[510][510];
int n, m, cnt, a, b;
int dfs(int x) {
    sou[x] = 1;
    if (path[x]) return path[x];
    for (int i = 1; i <= n; i++)
        if (vec[x][i])
            path[x] += dfs(i);
    return path[x];
}
int main() {
    int i;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        vec[a][b] = 1;
    }
    cin >> a >> b;
    path[b] = 1;
    cnt = dfs(a);
    int flag = 1;
    for (i = 1; i <= n; i++) {
        if (sou[i] && !path[i]) {
            flag = 0;
            break;
        }
    }
    cout << cnt << " ";
    if (!flag)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
