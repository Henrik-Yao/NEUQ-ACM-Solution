#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int N, M, f[20][maxn], dep[maxn];
struct person {
    string name;
    string fname;
    bool sex;
} a[maxn];
map <string, int> mp;
int lnk[maxn], tot;
struct edge { int v, nxt; } e[maxn];
inline void add_edge(int x, int y) {
    e[++tot] = { y, lnk[x] }, lnk[x] = tot, f[0][y] = x;
}
void dfs(int x, int d) {
    dep[x] = d;
    for (int k = lnk[x]; k; k = e[k].nxt)
        dfs(e[k].v, d + 1);
}
int LCA(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    int d = dep[y] - dep[x];
    for (int i = 0; (1 << i) <= d; ++i) if (d & (1 << i)) y = f[i][y];
    if (x != y) {
        for (int i = int(log2(N)); i >= 0; --i)
            if (f[i][x] != f[i][y])
                x = f[i][x], y = f[i][y];
        x = f[0][x];
    }
    return x;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("prob.in", "r", stdin);
#endif
    cin >> N;
    int len;
    for (int i = 1; i <= N; ++i) {
        cin >> a[i].name >> a[i].fname;
        mp[a[i].name] = i;
    }
    for (int i = 1; i <= N; ++i) {
        string& s = a[i].fname;
        len = s.length();
        switch (s[len - 1]) {
            case 'm': s.erase(s.begin() + len - 1), a[i].sex = 1; break;
            case 'f': s.erase(s.begin() + len - 1), a[i].sex = 0; break;
            case 'n': {
                s = s.substr(0, len - 4);
                a[i].sex = 1;
                add_edge(mp[s], i);
                break;
            }
            case 'r': {
                s = s.substr(0, len - 7);
                a[i].sex = 0;
                add_edge(mp[s], i);
                break;
            }
        }
    }
    for (int i = 1; i <= N; ++i) if (f[0][i] == 0) dfs(i, 1);
    for (int j = 1; (1 << j) <= N; ++j)
        for (int i = 1; i <= N; ++i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    cin >> M;
    string s, s1, s2;
    int x, y, lca;
    for (int i = 1; i <= M; ++i) {
        cin >> s1 >> s;
        cin >> s2 >> s;
        x = mp[s1], y = mp[s2];
        if (x == 0 || y == 0) {
            cout << "NA\n";
            continue;
        }
        if (a[x].sex == a[y].sex) cout << "Whatever\n";
        else {
            lca = LCA(x, y);
            if (lca == 0 || dep[x] - dep[lca] > 3 && dep[y] - dep[lca] > 3) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
