#include <algorithm>
#include <iostream>
using namespace std;
class Node //路径类
{
public:
    int a, b, c; //节点1，节点2，权
} list[1500];
int sign[1500];
int find(int);
bool compare(Node, Node);
main()
{
    int n, m, sum, num;
    while (cin >> n >> m)
    {
        sum = 0;
        num = 0;
        for (int i = 1; i <= n; i++)
        {
            sign[i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> list[i].a >> list[i].b >> list[i].c;
        }
        sort(list + 1, list + 1 + m, compare);//对路径按权进行排序
        for (int i = 1; i <= m; i++)//遍历所有路径
        {
            int u = list[i].a, v = list[i].b;
            if (find(u) == find(v)) //左节点和右节点已经被连接
            {
                continue;
            }
            num++;
            sign[find(u)] = find(v);//连接左节点和右节点
            sum += list[i].c;//加上权
        }
        if (num == n - 1)
        {
            cout << sum << endl;
        }
        else
            cout << "There is no minimum spanning tree." << endl;
    }
}
bool compare(Node a, Node b)
{
    return a.c < b.c;
}
int find(int x)
{
    if (sign[x] != x)
        sign[x] = find(sign[x]);
    return sign[x];
}