#include <bits/stdc++.h>
using namespace std;
int deg[105] = {0}, s[105] = {0};
int degflag = 0;
vector<vector<int>> a;
bool topo(int n)
{
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i])
        {
            q.push(i);
            degflag++;
        }
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        s[cnt++] = t;
        for (int i : a[t])
        {
            deg[i]--;
            if (!deg[i])
            {
                q.push(i);
            }
        }
    }
    return cnt == n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int d, u;
    for (int i = 0; i <= 104; ++i)
    {
        a.push_back(vector<int>());
    }
    while (cin >> n >> m)
    {
        memset(deg, 0, sizeof(deg));
        memset(s, 0, sizeof(s));
        for (int i = 0; i < m; ++i)
        {
            cin >> d >> u;
            a[d].push_back(u);
            deg[u]++;
            // cout << "a[d][u] = " << a[d] << endl;
        }
        bool flag = topo(n);
        // cout << "topo(n) = " << flag << endl;
        // cout << "degflag = " << degflag << endl;
        if (!flag)
        {
            cout << 0 << endl;
        }
        else if (flag && degflag != 1)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        for (int i = 0; i <= n; ++i)
        {
            a[i].clear();
        }
        degflag = 0;
    }
    return 0;
}
/*
5 4
1 5
5 2
3 2
4 3
*/