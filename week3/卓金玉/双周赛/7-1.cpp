#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > 0)
            flag = 1;
    }
    int b[n + 1][n + 1];
    memset(b, 0, sizeof(b));
    int i, j;
    int maxn = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {

            b[i][j] = max(b[i][j - 1], b[i - 1][j] + a[i]);
            if (b[i][j] > maxn)
                maxn = b[i][j];
        }
    }
    if (flag)
        cout << maxn;
    else
        cout << "0";
    return 0;
}
