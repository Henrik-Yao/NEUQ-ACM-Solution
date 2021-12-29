#include <iostream>
#include <map>
#include <deque>
using namespace std;
class Rote
{
public:
    deque<int> connect;
    int order;
    bool isdone = 0;
    int deep = 0;
};
Rote list[200];
void bfs(Rote, int);
bool can = 0;
main()
{
    int n, e;
    while (cin >> n >> e)
    {
        for (int p = 0; p < n; p++)
        {
            int a, t, c;
            cin >> a >> t;
            list[a].order = a;
            for (int i = 0; i < t; i++)
            {
                cin >> c;
                list[a].connect.push_back(c);
            }
        }
        for (int p = 0; p < e; p++)
        {
            int x, y;
            cin >> x >> y;
            bfs(list[x], y);

            if (can)
                cout << list[y].deep << endl;
            else
                cout << "connection impossible" << endl;
            for (int i = 0; i < n; i++) //清空
            {
                list[i].isdone = 0;
                list[i].deep = 0;
            }
            can = 0;
        }
        for (int i = 0; i < n; i++) //清空
        {
            list[i].connect.clear();
            list[i].isdone = 0;
            list[i].deep = 0;
        }
    }
}
void bfs(Rote a, int target)
{
    deque<Rote> que;
    que.push_back(a);
    while (que.size() != 0)
    {
        for (auto k = que.begin(); k != que.end(); k++) //遍历当前队列中所有的节点，k
        {
            for (auto it = k->connect.begin(); it != k->connect.end(); it++) //遍历k连接的节点加入队列
            {
                if (list[*it].isdone) //被遍历过
                {
                    continue;
                }
                list[*it].deep = k->deep + 1;
                list[*it].isdone = 1;
                que.push_back(list[*it]);
                if (list[*it].order == target) //发现目标
                {
                    can = 1;
                    return;
                }
            }
            que.pop_front(); //删除k
        }
    }
}