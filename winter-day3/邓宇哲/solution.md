# 7-1图的创建
~~~c++
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int value;
    map<int, int> connection; //节点对边权值的索引
};
main()
{
    int n, e;
    cin >> n >> e;
    Node list[n];
    for (int i = 0; i < e;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        list[a].value = a;
        list[a].connection[b] = c;
    }
    for (int i = 0; i < n;i++)
    {
        if(!list[i].connection.empty())
        {
            cout << i << ':';
            for (auto j = list[i].connection.begin(); j != list[i].connection.end();j++)
            {
                cout << '(' << i << ',' << j->first << ',' << j->second << ')';
            }
            cout << endl;
        }
    }
}
~~~
# 7-2图的删边操作
~~~c++
#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int value;
    map<int, int> connection; //节点对边权值的索引
};
main()
{
    int n, e;
    cin >> n >> e;
    Node list[n];
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        list[a].value = a;
        list[a].connection[b] = c;
    }
    int x;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].connection.erase(b);
    }
    for (int i = 0; i < n; i++)
    {
        if (!list[i].connection.empty())
        {
            cout << i << ':';
            for (auto j = list[i].connection.begin(); j != list[i].connection.end(); j++)
            {
                cout << '(' << i << ',' << j->first << ',' << j->second << ')';
            }
            cout << endl;
        }
    }
}
~~~
# 7-4岛屿数量
深度优先搜索，《山》
~~~c++
#include <algorithm>
#include <iostream>
using namespace std;
struct node
{
    int num = 0;
    bool done = 0;
};
node nodes[2002][2002];
void dfs(int, int);
int sum=0;
main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            cin >> nodes[i][j].num;
        }
    }
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            if((!nodes[i][j].done)&&nodes[i][j].num==1)
            {
                dfs(i, j);
                sum++;
            }
        }
    }
    cout << sum;
}
void dfs(int i ,int j)
{
    if (nodes[i][j].done==1)
    {
        return;
    }
    nodes[i][j].done = 1;
    if(nodes[i+1][j].num==1)
    {
        dfs(i + 1, j);
    }
    if(nodes[i-1][j].num==1)
    {
        dfs(i - 1, j);
    }
    if(nodes[i][j+1].num==1)
    {
        dfs(i, j+1);
    }
    if(nodes[i][j-1].num==1)
    {
        dfs(i , j-1);
    }
}
~~~
# 7-5繁忙的都市
~~~c++
#include <algorithm>
#include <iostream>
using namespace std;
class Node //路径类
{
public:
    int a, b, c; //节点1，节点2，权
} list[10000];
int sign[10000];
int find(int);
bool compare(Node, Node);
main()
{
    int n, m, maxx, num;
    cin >> n >> m;
    maxx = 0;
    num = 0;
    for (int i = 1; i <= n; i++)
    {
        sign[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> list[i].a >> list[i].b >> list[i].c;
    }
    sort(list + 1, list + 1 + m, compare); //对路径按权进行排序
    for (int i = 1; i <= m; i++)           //遍历所有路径
    {
        int u = list[i].a, v = list[i].b;
        if (find(u) == find(v)) //左节点和右节点已经被连接
        {
            continue;
        }
        num++;
        sign[find(u)] = find(v); //连接左节点和右节点
        maxx = max(maxx, list[i].c); //加上权
    }
    cout << num << ' ' << maxx;
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
~~~
# 7-6最小支撑树
~~~c++
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
~~~
# 7-8排列论文
~~~c++
#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
int howMuchBefore[1000];
deque<int> dict[1000];//节点名称对子节点的索引
deque<int> outcome; //保存结果
deque<int> list;   //队列
main()
{
    int n, m;
    while (cin >> n >> m)
    {
        bool sign = 0; //是否有多种结果
        int num = 0;  // 起点的数量
        for (int i = 1; i <= m; i++)
        {
            int d, u;
            cin >> d >> u;
            dict[d].push_back(u); //给节点d添加一个子节点u
            howMuchBefore[u]++;     //在u前面的论文个数增加
        }
        for (int i = 1; i <= n; i++)
        {
            if (howMuchBefore[i] == 0)//拓扑排序，先找出所有起点
            {              
                list.push_back(i); //找到就加入队列
                num++;
            }
        }
        if (num > 1) //起点太多，排序肯定不唯一
            sign = 1;
        while (!list.empty())
        {
            int p = list.front();//取队列中最前面的元素为p
            list.pop_front();//删去队列中最前的元素
            outcome.push_back(p);//添加到排序队列中去
            for (int i = 0; i < dict[p].size(); i++)//遍历p的子节点
            {
                int y = dict[p][i];
                howMuchBefore[y]--;//告诉这些子节点，在你们之前的元素减少一个
                if (!howMuchBefore[y])//如果y的前面没有元素了，只能直接将y放入队列
                {
                    list.push_back(y);
                }
            }
        }
        if (outcome.size() == n) //可以进行拓扑排序
        {
            if (!sign)
                cout << "1" << endl;
            else
                cout << "2" << endl;
        }
        else
            cout << "0" << endl;    //不能拓扑排序
        for (int i = 0; i < m; i++) //清空操作
            dict[i].clear();
        outcome.clear();
        while (!list.empty())
            list.pop_front();
        memset(howMuchBefore, 0, sizeof(howMuchBefore));
    }
}
~~~