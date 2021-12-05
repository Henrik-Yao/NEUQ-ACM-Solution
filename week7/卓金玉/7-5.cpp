#include <bits/stdc++.h>
using namespace std;
int dp[405][1505];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, C;
    while (cin >> N >> C)
    {
        int w[N + 1], v[N + 1];
        for (int i = 1; i <= N; ++i)
            cin >> w[i];
        for (int i = 1; i <= N; ++i)
            cin >> v[i];
        // for (int i = 0; i <= N; ++i)
        // {
        //     for (int j = 0; j <= C; ++j)
        //     {
        //         dp[i][j] = 0;
        //     }
        // }
        memset(dp, 0, sizeof(dp));
        int i, j;
        for (i = 1; i <= N; ++i)
        {
            for (j = 1; j <= C; ++j)
            {
                if (j >= w[i])
                {
                    dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
                // printf("%4d", dp[i][j]);
            }
            // cout << endl;
        }
        cout << dp[N][C] << endl;
    }
}