#include<bits/stdc++.h>

using namespace std;
#define N 10000
typedef struct node {
    int ww;
    int length;
} node;
vector<node> f[N];
typedef struct qq {
    int len = 0;
    vector<int> s;
} qq;
int v[N];

qq fim(int x, int y) {
    if (x == y) {
        qq c;
        c.len = 0;
        c.s.push_back(y);
        return c;
    }
    qq min;
    min.len = 100000;
    qq min1;
    v[x] = 1;
    for (auto it: f[x]) {
        if (!v[it.ww]) {
            qq c = fim(it.ww, y);
            int num = c.len;
            if (num + it.length < min.len) {
                min.len = num + it.length;
                min1 = c;
            }
        }
    }
    min.s = min1.s;
    min.s.push_back(x);
    v[x] = 0;
    return min;
}

void print(qq min) {
    auto it = min.s;
    for (int i = it.size() - 1; i >= 0; i--) {
        if (i != it.size() - 1)cout << "->" << it[i];
        else cout << it[i];
    }
    cout << ":" << min.len << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        int c;
        cin >> a >> b >> c;
        node p;
        p.ww = b;
        p.length = c;
        f[a].push_back(p);
    }
    qq s[n][n];
    qq max;
    max.len = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            s[i][j] = fim(i, j);
            if (s[i][j].len < 10000 && s[i][j].len > max.len)max = s[i][j];
        }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == y1)(printf("%d->%d:0\n", x1, y1));
    else if (s[x1][y1].len >= 10000) {
        printf("%d->%d:-1\n", x1, y1);
    } else print(s[x1][y1]);

    if (x2 == y2)(printf("%d->%d:0\n", x2, y2));
    else if (s[x2][y2].len >= 10000) {
        printf("%d->%d:-1\n", x2,y2);
    } else print(s[x2][y2]);

    print(max);
    return 0;
}