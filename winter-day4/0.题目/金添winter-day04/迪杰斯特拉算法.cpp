#include <bits/stdc++.h>
using namespace std;
// Dijkstra 迪杰斯特拉算法
int path[3000]; //记录路径
void dfs(int x)
{
    if (path[x] != -1)
    {
        dfs(path[x]);
    }
    else
        return;
    cout << "-->" << x;
}
   int n, e;            //顶点数和边数
    int G[3000][3000]; //构建图
 
int main()
{
    cin >> n >> e;
    memset(G, 0x3f, sizeof G);
    for (int i = 0; i < e / 2; i++)
    {
        int remp1, remp2, remp3;
        cin >> remp1 >> remp2 >> remp3;
        G[remp1][remp2] = remp3;
        G[remp2][remp1] = remp3;
    }
    int start, end;
    cin >> start >> end;
    int dis[5000]; //起点到各点的最短距离
    memset(path, -1, sizeof path);
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0; //标记起点入度为零
    bool visit[5090];
    memset(visit,0,sizeof(visit));
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        for (int j = 0; j < n; j++)
        {
            if ((u == -1 || dis[u] > dis[j]) && !visit[j])
            {
                u = j;
            }

        } // 每次寻找dis最小的节点切入
        if (u == -1)
            break;
        visit[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (G[u][j] == 0x3f3f3f3f)
                continue;
            if (dis[u] + G[u][j] < dis[j]) //每次以当前入度最小的点为中心，来更新其他点的入度
            {
                dis[j] = dis[u] + G[u][j];
                path[j] = u;
            }
        }
    }
    cout << start;
    if(start==end)
    {
        cout<<"-->"<<end;
    }
    else
    {
        dfs(end);
    }
    cout << ":";
    cout << dis[end];
    return 0;
}