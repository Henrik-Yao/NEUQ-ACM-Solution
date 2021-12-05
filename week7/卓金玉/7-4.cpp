#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N;
    cin >> T;
    int flag = 0;
    while (T--)
    {
        if (!flag)
        {
            flag++;
        }
        else
        {
            cout << endl;
        }
        cin >> N;
        int a[N], len[N], max = 1;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
            len[i] = 1;
        }
        for (int i = 1; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (a[i] > a[j] && len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    len[i] > max ? max = len[i] : 1;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}