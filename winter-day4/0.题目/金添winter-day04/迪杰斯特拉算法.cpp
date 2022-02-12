#include <bits/stdc++.h>
using namespace std;
// Dijkstra �Ͻ�˹�����㷨
int path[3000]; //��¼·��
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
   int n, e;            //�������ͱ���
    int G[3000][3000]; //����ͼ
 
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
    int dis[5000]; //��㵽�������̾���
    memset(path, -1, sizeof path);
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0; //���������Ϊ��
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

        } // ÿ��Ѱ��dis��С�Ľڵ�����
        if (u == -1)
            break;
        visit[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (G[u][j] == 0x3f3f3f3f)
                continue;
            if (dis[u] + G[u][j] < dis[j]) //ÿ���Ե�ǰ�����С�ĵ�Ϊ���ģ�����������������
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