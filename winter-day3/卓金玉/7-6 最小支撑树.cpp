#include <bits/stdc++.h>
using namespace std;
int f[1505];
typedef struct Edge
{
    int x, y, w;
} EDGE;
bool cmp(EDGE v1, EDGE v2)
{
    return v1.w < v2.w;
}
int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if (a != b)
    {
        f[a] = b;
    }
}
int main()
{
    int n, e;
    while (cin >> n >> e)
    {
        EDGE node[e + 1];
        int flag[1505] = {0};
        int a, b, c;
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }
        for (int i = 0; i < e; i++)
        {
            cin >> a >> b >> c;
            node[i].x = a;
            node[i].y = b;
            node[i].w = c;
            merge(a, b);
        }
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            f[i] == i ? num++ : 1;
        }
        if (num == 1)
        {
            sort(node, node + e, cmp);
            int cnt = 0;
            for (int i = 0; i < e; i++)
            {
                if (flag[node[i].x] == 1 && flag[node[i].y] == 1)
                {
                    continue;
                }
                else
                {
                    flag[node[i].x] = 1;
                    flag[node[i].y] = 1;
                    cnt += node[i].w;
                }
            }
            cout << cnt << endl;
        }
        else
        {
            cout << "There is no minimum spanning tree." << endl;
        }
    }
    return 0;
}
