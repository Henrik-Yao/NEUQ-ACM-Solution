#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 1000;
int n, m, G[maxn][maxn], deg[maxn], topo[maxn];
int sig = 0;

bool toposort() {
    int cnt = 0;
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0)q.push(i);
    }
    while (!q.empty()) {
        if (q.size() > 1)sig = 2;
        int u = q.front(); q.pop();
        topo[cnt++] = u;
        for (int v = 1; v <= n; v++) if (G[u][v]) {
            deg[v]--;
            if (deg[v] == 0)q.push(v);
        }
    }
    if (n == cnt) {
        if (!sig)sig = 1;
    }
    else sig = 0;
    return true;
}

int main() {
    while (cin >> n >> m) {
        sig = 0;
        memset(G, 0, sizeof(G));
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u][v] = 1;
            deg[v]++;
        }
        toposort();
        cout << sig << endl;
    }
}