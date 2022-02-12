#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 500+5;
const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };
int d[maxn][maxn];

int G[maxn][maxn];

int r0, c0, dir, r1, c1, r2, c2, len, height;

struct Node {
    int r, c;
    int dis;
    Node(int r = 0, int c = 0, int dis = -1) :r(r), c(c), dis(dis) {}
    bool operator < (const Node &rhs)const
    {
        return dis > rhs.dis;
    }
};

Node p[maxn][maxn];

bool read_case() {
    cin >> len >> height;
    cin >> r0 >> c0 >> r2 >> c2;
    memset(G, 0, sizeof(G));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < len; j++)
            cin >> G[i][j];
    r1 = r0; c1 = c0;
    return true;
}

void print_ans(Node u) {
    for (;;) {
        cout << "(" << u.r << " " << u.c << ")";
        if (u.dis == 0) break;
        u = p[u.r][u.c];
    }
        
}

Node walk(const Node &u, int turn) {
    return Node(u.r + dr[turn], u.c + dc[turn]);
}

bool inside(int r, int c) {
    return r >= 1 && r < height && c >= 1 && c < len && G[r][c]>0;
}

void solve() {
    priority_queue<Node>q;
    memset(d, -1, sizeof(d));
    Node u(r1, c1, 0);
    q.push(u);
    while (!q.empty()) {
        Node u = q.top(); q.pop();
        if (u.r == r2 && u.c == c2) { 
            print_ans(u);
            return; 
        }
        for (int i = 0; i < 4; i++) {
            Node v = walk(u, i);
            if (inside(v.r, v.c) && d[v.r][v.c] < 0) {
                v.dis = u.dis + G[v.r][v.c];
                d[v.r][v.c] = 0;
                p[v.r][v.c] = u;
                q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}
int main() {
    read_case();
    solve();
}
