#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n, m, ans;
char s[1010][1010];
int res[1010][1010], v[1010][1010];
vector< pair<int, int> > G;

void dfs(int x, int y)
{
    v[x][y] = 1; ++ans;
    G.push_back(make_pair(x, y));
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > n || v[nx][ny]) continue;
        if(s[nx][ny] == s[x][y]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(v[i][j]) continue;
            dfs(i, j);
            for(auto x: G) res[x.first][x.second] = ans;
            G.clear(); ans = 0;
        }
    while(m--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", res[u][v]);
    }
}