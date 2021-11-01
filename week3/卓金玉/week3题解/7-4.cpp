#include <bits/stdc++.h>
int n, m, a[1000001][3], cnt, aa[100001], k;
int x[4] = {0, 1, 0, -1}, y[4] = {1, 0, -1, 0}, d[1001][1001];
bool b[1001][1001];
inline void bfs(int i, int j)
{
    cnt++;
    d[i][j] = k;
    int fm = 1, lt = 2;
    a[2][1] = i, a[2][2] = j;
    while (fm < lt)
    {
        fm++;
        for (register int q = 0; q <= 3; q++)
        {
            int xa = a[fm][1] + x[q];
            int ya = a[fm][2] + y[q];
            if (xa > 0 && xa <= n && ya > 0 && ya <= n && !d[xa][ya] && b[a[fm][1]][a[fm][2]] != b[xa][ya])
            {
                cnt++;
                lt++;
                a[lt][1] = xa;
                a[lt][2] = ya;
                d[xa][ya] = k;
            }
        }
    }
    aa[k] = cnt;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= n; j++)
        {
            char c;
            scanf(" %c", &c);
            if (c == '1')
                b[i][j] = 1;
        }
    for (register int i = 1; i <= m; i++)
    {
        int xb, yb;
        scanf("%d%d", &xb, &yb);
        k++;
        if (d[xb][yb])
            cnt = aa[d[xb][yb]];
        else
            bfs(xb, yb);
        printf("%d\n", cnt);
        cnt = 0;
    }
}
