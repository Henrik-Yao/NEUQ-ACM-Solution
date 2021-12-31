#include <bits/stdc++.h>
using namespace std;
map<string, string> mp;
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        mp[b] = a;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (mp.count(s)) cout << mp[s] << endl;
        else cout << "eh" << endl;
    }
    return 0;
}