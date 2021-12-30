#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
map<string, string> parent; // 映射父母
map<string, int> gender; // 映射性别 1 为 男
set<string> exist; // 记录某人是否存在
int check(string last1, string last2) {
    int f1 = 1, f2 = 1;
    for (string sa = last1; sa.size() > 0; sa = parent[sa], f1++) {
        f2 = 1;
        for (string sb = last2; sb.size() > 0; sb = parent[sb], f2++) {
            if (f1 > 4 && f2 > 4) return 1;
            if (sa == sb && (f1 <= 4 || f2 <= 4)) return 0;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string last, family;
        cin >> last >> family;
        int len = family.size();
        if (family[len - 1] == 'n') {
            gender[last] = 1; exist.insert(last);
            parent[last] = family.substr(0, len - 4);
        } else if (family[len - 1] == 'r') {
            gender[last] = 0; exist.insert(last);
            parent[last] = family.substr(0, len - 7);
        } else if (family[len - 1] == 'm') {
            gender[last] = 1; exist.insert(last);
        } else if (family[len - 1] == 'f') {
            gender[last] = 0; exist.insert(last);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string last1, family1, last2, family2;
        cin >> last1 >> family1 >> last2 >> family2;
        if (!exist.count(last1) || !exist.count(last2)) {
            cout << "NA" << endl;
        } else if (gender[last1] == gender[last2]) {
            cout << "Whatever" << endl;
        } else {
            if (check(last1, last2) == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        
    }
    return 0;
}