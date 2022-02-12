#include <iostream>
#include <vector>
using namespace std;

typedef struct Node
{
    int v, w;
}Node;

const int infinity = 65535;
int n, e, s, d;
int dis[1001], pre[1001];
vector<Node> v[1001];
bool vis[1001] = {false};

void dijkstra(int s) {
    fill(dis, dis + 1001, infinity);

    dis[s] = 0;
    for (int i = 0; i < n; i++) 
    {
        int u = -1, min = infinity;
        for (int j = 0; j < n; j++) 
        {
            if (!vis[j] && dis[j] < min) 
            {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1)
        {
            break;
        }

        vis[u] = true;

        for (int j = 0; j < v[u].size(); j++) 
        {
            int x = v[u][j].v;
            if (!vis[x] && dis[u] + v[u][j].w < dis[x]) 
            {
                dis[x] = dis[u] + v[u][j].w;
                pre[x] = u;
            }
        }
    }
}

int main() {
    cin>>n>>e;
    for (int i = 0; i < e / 2; i++) 
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(Node{b, c});
        v[b].push_back(Node{a, c});
    }
    cin>>s>>d;
    if (s == d) 
    {
        printf("%d-->%d:0", s,s);
        return 0;
    }
    dijkstra(s);

    vector<int> ve;
    int x = d;
    while (x != s) 
    {
        ve.push_back(x);
        x = pre[x];
    }
    cout<<s;

    for (int i = ve.size() - 1; i >= 0; i--)
    {
        printf("-->%d", ve[i]);
    }
    printf(":%d", dis[d]);
    return 0;
}
