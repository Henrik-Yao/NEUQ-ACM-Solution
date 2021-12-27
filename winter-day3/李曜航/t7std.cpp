#include <algorithm>
#include <iostream>
using namespace std;
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
struct Road
{
    int u;
    int v;
    int w;
} road[65];

int fa[65];

bool cmp(Road r1, Road r2) { return r1.w < r2.w; }

void init()
{
    for (int i = 0; i < 60; i++)
        fa[i] = i;
}

int find(int x)
{
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}


inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int main()
{
    int n, v, m;
    while (scanf("%d %d %d", &n, &v, &m) != EOF)
    {
        init();
        for (int i = 1; i <= m; i++)
            road[i].u = read(), road[i].v = read(), road[i].w = read();

        int maxroads = 0, sum = 0, num = 0;
        sort(road+1, road + 1 + m, cmp);
        for (int i = 1; i <= m; i++)
        {
            if ((road[i].u == v || road[i].v == v) && maxroads < 2)
            {
                if (find(road[i].u)!= find(road[i].v))
                {
                    merge(road[i].u, road[i].v);
                    sum += road[i].w;
                    maxroads++;
                    num++;
                }
            }
            else if (road[i].u != v && road[i].v != v)
            {
                if (find(road[i].u)!= find(road[i].v))
                {
                    merge(road[i].u,road[i].v);
                    sum += road[i].w;
                    num++;
                }
            }
            if (num == n - 1)
                break;
        }
        if (num == n - 1 && maxroads <= 2)
            printf("%d\n", sum);
        else
            printf("-1\n");
    }
    return 0;
}
