#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int start; //起始节点
    int next;  //终点节点
    int cost;  //权重
};
int bond[100]; //并查集数组
int find_bond(int n)
{
    if (bond[n] == n)
        return n;
    else
        return find_bond(bond[n]);
}
bool cmp(Edge a, Edge b)
{
    return a.cost < b.cost;
}
int main()
{
    int n, v, e; // n为1~n号，v是特殊城镇的编号，e是边数
    while (cin >> n >> v >> e)
    {
        int visit[100];
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; i++)
            bond[i] = i;
        Edge road[60];
        int num = 0;
        for (int i = 0; i < e; i++)
        {
            int remp1, remp2, remp3;
            cin >> remp1 >> remp2 >> remp3;
            road[i].start = remp1;
            road[i].next = remp2;
            road[i].cost = remp3;
            num++;
        }
        sort(road, road + num, cmp);
        int mst = 0;  //最小生成树
        int flag = 0; //记录其联通的个数
        for (int i = 0; i < num; i++)
        {
            if (find_bond(road[i].start) != find_bond(road[i].next)) //若还没有联通，则联通
            {
                if((road[i].start==v||road[i].next==v)&&visit[v]==2)
                continue;
                bond[find_bond(road[i].start)] = bond[road[i].next];
                mst += road[i].cost;
                flag++;
                visit[road[i].start]++;
                visit[road[i].next]++;
            }
            if (flag == n - 1)
                break;
        }
        bool judge = 1;
        int boss = find_bond(0);
        for (int i = 0; i < n; i++)
        {
            if (find_bond(i) != boss)
            {
                judge = 0;
            }
        }
        if (judge)
            cout << mst << endl;
        else
            cout << "-1" << endl;
        memset(bond, 0, sizeof(bond));
    }
    return 0;
}
 