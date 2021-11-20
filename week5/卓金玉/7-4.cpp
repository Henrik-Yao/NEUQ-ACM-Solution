#include <bits/stdc++.h>
using namespace std;
#define N 2005
bool G[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
void dfs(int x, int y)
{
    G[x][y] = 0;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if ((0 <= tx && tx < n) && (0 <= ty && ty < m) && G[tx][ty])
        {
            dfs(tx, ty);
        }
    }
}
int search()
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (G[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    scanf("%d %d", &n, &m);
    memset(G, 0, sizeof(G));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &G[i][j]);
        }
    }
    printf("%d\n", search());

    return 0;
}