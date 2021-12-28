#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int u;
    int v;
    int w;
} Road;

Road road[51];
int f[51];

bool cmp(Road r1, Road r2) { return r1.w < r2.w; }

void init() {
    for (int i = 0; i < 51; i++) {
        f[i] = i;
    }
}

int find(int x) {
    if (x == f[x])
        return x;
    return f[x] = find(f[x]);
}

int merge(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        f[b] = a;
        return 1;
    }
    return 0;
}

int main() {
    int n, v, e;
    while (scanf("%d %d %d", &n, &v, &e) != EOF) {
        init();
        for (int i = 0; i < e; i++) {
            scanf("%d %d %d", &road[i].u, &road[i].v, &road[i].w);
        }
        int cnt = 0, sum = 0, num = 0;
        sort(road, road + e, cmp);
        for (int i = 0; i < e; i++) {
            if ((road[i].u == v || road[i].v == v) && cnt < 2) {
                if (merge(road[i].u, road[i].v)) {
                    sum += road[i].w;
                    cnt++;
                    num++;
                }
            } else if (road[i].u != v && road[i].v != v) {
                if (merge(road[i].u, road[i].v)) {
                    sum += road[i].w;
                    num++;
                }
            }
            if (num == n - 1)
                break;
        }
        if (num == n - 1 && cnt <= 2)
            printf("%d\n", sum);
        else
            printf("-1\n");
    }
    return 0;
}
