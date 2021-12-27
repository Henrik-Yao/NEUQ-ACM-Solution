# 7-1二叉树叶结点值和最大层
~~~c++
#include <iostream>
using namespace std;
int list[100];
int sum[100];
int connect(int, int);
main()
{
    int num = 0; //用于更新数组下标的变量
    while (cin >> list[num++])
        ; //输入数据存入数组中
    sum[0] = list[0];
    connect(0, 1); //从第一层开始计算和
    int point = 0;
    for (int i = 0; i < 100; i++)
    {
        if (abs(sum[i]) >= abs(sum[point]))//找最大的最末尾的
        {
            point = i;
        }
    }
    cout << point;
}
int connect(int point, int deep) //传入当前元素下标，当前元素深度，返回当前元素的值，并且计算下一层的和
{
    static int L = point;//常量指针，起到值传递的
    if (list[L] == 0) // point指向的元素为0，则return 0;
    {
        return 0;
    }
    int a = list[L];
    sum[deep] += connect(++L, deep+1); //下一层的和+=左分支的值
    sum[deep] += connect(++L, deep+1); //下一层的和+=右分支的值
    return a;                            //返回当前元素的值
}
~~~
# 7-3树最近公共祖先
~~~c++
#include <deque>
#include <iostream>
using namespace std;
deque<int> list[100];//为100个数保存其子节点
int search(int);
int connect(int);
int y, z;
main()
{
    int n;
    int pozition;
    int t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            list[j].clear();
        }
        cin >> pozition;
        connect(pozition);
        cin >> t >> y >> z;//读取要搜索的节点
        cout << search(pozition) << endl;//从根节点为起点
    }
}
int search(int n)//传入节点
{
    if (n == y || n == z)//目标竟是我自己
    {
        return n;
    }
    if (!list[n].size())//该节点没有子节点，且不是目标
    {
        return -1;
    }
    int k[3] = {-1, -1, -1}, t = 0;
    for (int i = 0; i < list[n].size(); i++)//遍历所有的子节点
    {
        int f = search(list[n][i]);
        if (f != -1)//子节点存在子节点 或 发现目标
        {
            k[++t] = f;
        }
    }
    if (t == 2)//存在目标的子节点的节点数为2 或目标已经找全
    {
        return n;//返回该节点
    }
    else if (t == 1)//存在目标子节点的节点数为1 或 只找到一个目标
    {
        return k[t];//返回子节点
    }
    else //有子节点,但没找到目标
    {
        return -1;
    }
}
int connect(int n)//传入当前节点的值，连接其子节点
{
    int p = 1;//初始化不为0的数
    while (p != 0)
    {
        cin >> p;//传入子节点的值
        if (p != 0)//子节点不是0
        {
            list[n].push_back(p);//添加该子节点
            connect(p);//对子节点进行该操作
        }
    }
    return 0;
}
~~~
# 7-4罪犯帮派
~~~c++
#include <iostream>
#include <set>
using namespace std;
int list[100];
int search(int);
int main()
{
    int n, m, q;
    int x, y;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) //每个罪犯属于不同帮派
    {
        list[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (x == y) //相等无意义
        {
            continue;
        }
        x = search(x);
        y = search(y);
        list[y] = x; //两个属于相同的帮派
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        if (search(x) == search(y))
        {
            cout << "In the same gang.";
        }
        else
        {
            cout << "In different gangs.";
        }
        cout << endl;
    }
    set<int> sets; //用set来看看有几个帮派
    for (int i = 1; i <= n; i++)
    {
        sets.insert(search(i));
    }
    cout << sets.size() << endl;
}
int search(int x) //输入罪犯编号，看看属于那个帮派
{
    if (list[x] == x) //如果是相等的，则未被记录，则返回自身
    {
        return x;
    }
    else                                  //有记录
        return list[x] = search(list[x]); //看看记录对应着什么，并更新记录，返回
}
~~~
# 7-5二叉树路径和
~~~c++
#include <bits/stdc++.h>
using namespace std;
inline int read() //获得数字读取信息
{
    int ret = 0, f = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -f;
    for (; isdigit(ch); ch = getchar())
        ret = ret * 10 + ch - 48;
    return ret * f;
}
const int maxn = 100;
struct Tnode
{
    int w, fa, son[2]; //值，父节点，子节点
};
Tnode a[maxn];            //节点数组
map<int, vector<int>> mp; //保存 特定数值对应的节点的层数
int T, N, K, dis[maxn];   // T为数据组数,N为节点数，dis为保存路径的数值和的数组
int Len, End;             // Len为最小的路径长度，End为路径的末端

void dfs(int x) //存取节点并且计算路径的数值和
{
    for (int i = 0; i < 2; ++i) //对两个子节点进行操作
    {
        int r = read();                   //读取数据
        a[x].son[i] = (r == 0) ? 0 : ++N; //如果是0，子节点的索引就为0（空值）。不为0，则节点数量增加1
        if (r == 0)
            continue;            //开始对剩下的子节点进行操作
        a[N].fa = x, a[N].w = r; //对新节点数据进行保存
        dis[N] = dis[x] + r;     //计算并且保存新节点的路径数值和
        dfs(N);                  //以新节点为起点继续进行操作
    }
}

void find(int x, int dep) //下标，层数
{
    if (!mp[dis[x] - K].empty()) // dis[x] - K为某一节点的路径数值和，mp[dis[x] - K]不为空，说明已经被记录
    {
        int L = dep - mp[dis[x] - K].back(); //当前深度减去该路径和的最深深度即为所求的长度
        if (L <= Len)                        //找最小长度的且最靠右边的路径
            Len = L, End = x;
    }
    mp[dis[x]].push_back(dep);  //增加一个 路径数值和对节点层数的索引
    for (int i = 0; i < 2; ++i) //分别对两个子节点进行操作
        if (a[x].son[i])//如果子节点存在
            find(a[x].son[i], dep + 1);
    mp[dis[x]].pop_back(); //删除此索引
}

void write(int x, int Len) //通过路径的末端和路径的长度，溯源输出
{
    if (Len == 0)
        return;
    write(a[x].fa, Len - 1);
    printf("%d ", a[x].w);
}

main()
{
    T = read();
    while (T--) // T是次数
    {
        N = 1;                    //初始化节点的个数为1
        dis[1] = a[N].w = read(); //读入给数组的下标1的元素
        dfs(1);                   //从下标1开始读入
        Len = N + 1;
        K = read(); //读入k
        mp.clear();
        mp[0].push_back(0); //为map新建一个索引为0的队列，并且队列只有一个0值
        find(1, 1);         //从下标1开始搜索，并传入当前层数1
        if (Len == N + 1)
            puts("no available path");
        else
            write(End, Len), puts(""); //通过路径的末端和路径的长度，溯源输出
    }
}
~~~
# 7-6先序和中序构造二叉树
~~~c++
#include <iostream>
using namespace std;

class Node
{
public:
    Node *pointl, *pointr;
    int value;
    Node();
};
int find(int *, int, int);
Node *connect(int, int *, int *);
void out(Node *);
int mid[1009] = {0}, pre[1009] = {0};
main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> mid[i];
    Node *point = connect(n, mid, pre);
    out(point);
}
int find(int *a, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return 0;
}
void out(Node *point)
{
    if (point == NULL)
        return;

    out(point->pointl);
    out(point->pointr);
    cout << point->value << " ";
}
Node *connect(int n, int *a, int *b)
{
    if (n <= 0)
        return NULL;
    Node *x;
    x = new Node;
    x->value = b[0];
    int t = find(a, b[0], n);
    x->pointl = connect(t, a, b + 1);
    x->pointr = connect(n - t - 1, a + t + 1, b + t + 1);
    return x;
}
Node::Node()
{
    pointl = pointr = NULL;
}
~~~
# 7-7按层遍历二叉树
~~~c++
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *pointl, *pointr;
    int value;
    Node();
};

int mid[1009], pre[1009];
int find(int *, int, int);
Node *connect(int, int *, int *);

main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mid[i];
    }
    Node *point = connect(n, mid, pre);
    queue<Node *> list;
    list.push(point);
    while (!list.empty())
    {
        Node *node = list.front();
        list.pop();
        cout << node->value << " ";
        if (node->pointl)
        {
            list.push(node->pointl);
        }
        if (node->pointr)
        {
            list.push(node->pointr);
        }
    }
}
int find(int *a, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return 0;
}
Node *connect(int n, int *a, int *b)
{
    if (n <= 0)
        return NULL;
    Node *x;
    x = new Node;
    x->value = b[0];
    int t = find(a, b[0], n);
    x->pointl = connect(t, a, b + 1);
    x->pointr = connect(n - t - 1, a + t + 1, b + t + 1);
    return x;
}
Node::Node()
{
    pointl = pointr = NULL;
}
~~~
# 7-9后序和中序构造二叉树
~~~c++
#include <iostream>
using namespace std;

class Node
{
public:
    Node *pointl, *pointr;
    int value;
    Node();
};
int mid[1000] = {}, after[1000] = {};
int find(int *, int, int);
Node *connect(int, int *a, int *b);
void pre(Node *);

main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> after[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> mid[i];
    }
    Node *point = connect(n, mid, after);
    pre(point);
}
int find(int *a, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return 0;
}
Node::Node()
{
    pointl = pointr = NULL;
}
Node *connect(int n, int *a, int *b)
{
    if (n <= 0)
    {
        return NULL;
    }
    Node *nod = new Node;
    nod->value = b[n - 1];
    int t = find(a, b[n - 1], n);
    nod->pointl = connect(t, a, b);
    nod->pointr = connect(n - t - 1, a + t + 1, b + t);
    return nod;
}
void pre(Node *point)
{
    if (point == NULL)
        return;
    cout << point->value << " ";
    pre(point->pointl);
    pre(point->pointr);
}
~~~