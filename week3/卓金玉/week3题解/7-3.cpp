#include <bits/stdc++.h>
using namespace std;
int fld[21][21], mine[21][21], vis[21][21], cfld[21][21];
int n, m, k, l, num;
int dx[8] = {1, -1, -1, -1, 0, 0, 1, 1};
int dy[8] = {1, -1, 0, 1, -1, 1, -1, 0};
int judge(int x, int y);
int cfcg(int x, int y);
void f(int x, int y);
int main()
{
    int a, b;
    scanf("%d %d %d %d", &n, &m, &k, &l);
    memset(fld, -1, sizeof(fld));
    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &a, &b);
        mine[a][b] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cfld[i][j] = cfcg(i, j);
        }
    }
    for (int i = 0; i < l; ++i)
    {
        int xi, yi;
        cin >> xi >> yi;
        if (mine[xi][yi] == 1)
        {
            printf("You lose");
            break;
        }
        if (fld[xi][yi] != -1)
            continue;
        if (fld[xi][yi] == -1)
        {
            f(xi, yi);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("%d ", fld[i][j]);
                }
                printf("\n");
            }
        }
        if (n * m - k == num)
        {
            printf("You win");
        }
        printf("\n");
    }
    return 0;
}
void f(int x, int y)
{
    vis[x][y] = 1;
    if (!judge(x, y))
    {
        fld[x][y] = cfld[x][y];
        for (int i = 0; i < 8; ++i)
        {
            int xi = x + dx[i];
            int yi = y + dy[i];
            if (xi < 0 || xi >= n || yi < 0 || yi >= m || vis[xi][yi])
                continue;
            f(xi, yi);
        }
    }
    else
    {
        fld[x][y] = cfld[x][y];
    }
    num++;
}
int cfcg(int x, int y)
{
    int re = 0;
    for (int i = 0; i < 8; i++)
    {
        int xi, yi;
        xi = x + dx[i];
        yi = y + dy[i];
        if (xi < 0 || xi >= n || yi < 0 || yi >= m)
            continue;
        if (mine[xi][yi] == 1)
            re++;
    }
    return re;
}
int judge(int x, int y)
{
    int re = 0;
    for (int i = 0; i < 8; i++)
    {
        int xi, yi;
        xi = x + dx[i];
        yi = y + dy[i];
        if (xi < 0 || xi >= n || yi < 0 || yi >= m)
            continue;
        if (mine[xi][yi] == 1)
            re = 1;
    }
    return re;
}
