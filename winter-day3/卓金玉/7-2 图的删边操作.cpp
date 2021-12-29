#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, e;
    cin >> n >> e;
    map<int, map<int, int>> m;
    int a, b, c;
    int t;
    for (int i = 0; i < e; ++i)
    {
        cin >> a >> b >> c;
        if (!i)
        {
            t = a;
        }
        m[a][b] = c;
    }
    int d;
    cin >> d;
    // map<int, int> temp;
    for (int i = 0; i < d; ++i)
    {
        cin >> a >> b;
        // auto delita = m.find(a);
        // temp = delita->second;
        // auto delitb = temp.find(b);
        m[a].erase(b);
        if (!m[a].size())
        {
            m.erase(a);
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ":";
        for (auto itt : it->second)
        {
            cout << "(" << it->first << "," << itt.first << "," << itt.second << ")";
        }
        cout << endl;
    }
    return 0;
}
