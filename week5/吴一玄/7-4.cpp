#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, ans;
int a[2010][2010];

void dfs(int x, int y)
{
    a[x][y] = 0;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(!a[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
         scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(!a[i][j]) continue;
            dfs(i, j);
            ++ans;
        }
    printf("%d\n", ans);
    return 0;
}