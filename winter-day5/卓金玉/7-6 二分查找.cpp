#include <bits/stdc++.h>
using namespace std;
// int a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, quest;
    set<int> s;
    int num;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            s.insert(num);
        }
        // int i = 0;
        // memset(a, 0, sizeof(a));
        map<int, int> m;
        int i = 1;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            // a[i] = *it;
            // i++;
            if (it == s.begin())
            {
                cout << *it;
            }
            else
            {
                cout << " " << *it;
            }
            m[*it] = i;
            i++;
        }
        cout << endl;
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            cin >> quest;
            auto it = m.find(quest);
            if (it != m.end())
            {
                if (i == 0)
                    cout << it->second;
                else
                    cout << " " << it->second;
            }
            else
            {
                if (i == 0)
                    cout << "0";
                else
                    cout << " 0";
            }
        }
        cout << endl;
        s.clear();
    }

    return 0;
}