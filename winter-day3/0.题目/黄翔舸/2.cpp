#include<bits/stdc++.h>
#include<cstring>
#include<map>
using namespace std;

int main() {
    int n, e, a, b, c, m;
    cin >> n >> e;
    map<int, map<int, int>> tu;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        tu[a][b] = c;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        tu[a].erase(b);
    }
    for (auto i : tu) {
        int a = i.first;
        string s = "";
        for (auto j : i.second) {
            s += "(" + to_string(a) + "," + to_string(j.first) + "," + to_string(j.second) + ")";
        }
        if (s != "") cout << a << ":" << s << endl;
    }
    return 0;
}