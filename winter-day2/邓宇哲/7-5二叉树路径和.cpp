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
