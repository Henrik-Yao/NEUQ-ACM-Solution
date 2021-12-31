#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<char> pattern;
    string s, p;
    while (getline(cin, s))
    {
        getline(cin, p);
        for (int i = 0; i < p.length(); ++i)
        {
            pattern.insert(p[i]);
        }
        int cnt = pattern.size();
        for (int i = 0; i < s.length(); ++i)
        {
            pattern.insert(s[i]);
            if (pattern.size() != cnt)
            {
                cout << s[i];
                pattern.erase(s[i]);
            }
        }
        cout << endl;
        s.clear();
        p.clear();
        pattern.clear();
    }

    return 0;
}