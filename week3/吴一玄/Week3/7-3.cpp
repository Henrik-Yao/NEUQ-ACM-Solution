#include<bits/stdc++.h>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int n, m, k, l;
int is[30][30], v[30][30];

void open(int x, int y)
{
    int res = 0;
    for(int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(is[nx][ny]) ++res;
    }
    v[x][y] = res;
    if(res) return;
    for(int i = 0; i < 8; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(is[nx][ny] || v[nx][ny] != -1) continue;
        open(nx, ny);
    }
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &l);
    while(k--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        ++x, ++y;
        is[x][y] = 1;
    }
    memset(v, -1, sizeof(v));
    while(l--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        ++x, ++y;
        if(v[x][y] != -1) continue;
        if(is[x][y]) {puts("You lose"); return 0;}
        open(x, y);
        for(int i = 1; i <= n; ++i, puts(""))
            for(int j = 1; j <= m; ++j)
                printf("%d ", v[i][j]);
        int flag = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(v[i][j] == -1 && !is[i][j]) flag = 0;
        if(flag) {puts("You win"); return 0;}
        puts("");
    }
    return 0;
}