#include <bits/stdc++.h>
using namespace std;
struct Mp
{
    int cnct[101][101];
    int v, w;
};
int main()
{
    int n;
    Mp m;
    scanf("%d %d %d", &m.v, &n, &m.w);
    int safeCity[101];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &safeCity[i]);
    }
    for (int i = 0; i < m.v; i++)
    {
        for (int j = 0; j < m.v; j++)
        {
            m.cnct[i][j] = 0;
        }
    }
    for (int i = 0; i < m.w; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        m.cnct[x][y] = 1;
        m.cnct[y][x] = 1;
    }
    int now, target, flag = 0;
    scanf("%d %d", &now, &target);
    for (int i = 0; i < n; i++)
    {
        if (target == safeCity[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        if (m.cnct[now][target])
        {
            printf("The city %d can arrive safely!", target);
        }
        else
        {
            printf("The city %d can not arrive safely!", target);
        }
    }
    else
    {
        if (m.cnct[now][target])
        {
            printf("The city %d is not safe!", target);
        }
        else
        {
            printf("The city %d is not safe!", target);
        }
    }
    return 0;
}
