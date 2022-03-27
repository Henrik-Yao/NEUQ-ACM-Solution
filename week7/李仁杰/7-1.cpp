#include <iostream>
#include <map>
using namespace std;

int base = 1e9 + 7;
map<string, string> ma;

int toNum(char c) {
    return c - 'a';
}

int toHash(string s) {
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans = (ans * 26 + toNum(s[i])) % base;
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        ma.insert(make_pair(s2, s1));
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (ma.find(s) != ma.end()) cout << (*ma.find(s)).second << endl;
        else cout << "eh\n";
    }
}