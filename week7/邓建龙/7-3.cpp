#include <bits/stdc++.h>
using namespace std;
int n, m;
string S, s;
map<char, int> mp;
int main()
{
    while (getline(cin, S)) {
        getline(cin, s);
        vector<char> vec;
        n = S.size(), m = s.size();
        for (int i = 0; i <= m; i++) {
            if (!mp.count(s[i])) mp[s[i]] = 1;
        }
        for (int i = 0; i <= n; i++) {
            if (mp.count(S[i])) continue;
            else vec.push_back(S[i]);
        }
        for (int i = 0; i < vec.size(); i++) {
            i != vec.size() - 1 ? cout << vec[i] : cout << vec[i] << endl;
        }
        vec.clear();
        S = "", s = "";
        mp.clear();
    }
    return 0;
}