#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 1, n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    queue<int> q[n + 1];
    int num[n + 1];
    int sign = 0;
    for (int i = 1; i <= n; ++i)
    {

        if (q[cnt].empty())
        {
            q[cnt].push(a[i]);
            num[cnt] = a[cnt];
            a[i] == 1 ? sign = 1 : 1;
        }
        else
        {
            int flag = 1;
            for (int j = 1; j <= cnt; ++j)
            {
                if (a[i] < num[j])
                {
                    num[j] = a[i];
                    q[j].push(a[i]);
                    flag = 0;
                    a[i] == 1 ? sign = j : 1;
                    break;
                }
            }
            if (flag)
            {
                cnt++;
                num[cnt] = a[i];
                q[cnt].push(a[i]);
                a[i] == 1 ? sign = cnt : 1;
            }
        }
    }
    int t;
    // cout << sign << endl;
    while (!q[sign].empty())
    {
        t = q[sign].front();
        q[sign].pop();
        cout << t << " ";
    }
    cout << endl
         << cnt << endl;
    return 0;
}
