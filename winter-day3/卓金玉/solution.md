# 寒假集训—day3(图)
## 7-1 图的创建
### 题面
请编写程序创建一个有向图。有向图中包含n个顶点，编号为0至n-1。
**输入格式:**
输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过20000。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值。各边并非按端点编号顺序排列。
**输出格式:**
按顶点编号递增顺序输出每个顶点引出的边，每个顶点占一行，若某顶点没有引出边，则不输出。每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，表示有向边a->b的权值为w，a引出的多条边按编号b的递增序排列。
**输入样例:**
在这里给出一组输入。例如：
```
7 7
0 1 5
0 3 7
0 6 6
1 2 4
2 5 1
3 5 3
6 5 4
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
0:(0,1,5)(0,3,7)(0,6,6)
1:(1,2,4)
2:(2,5,1)
3:(3,5,3)
6:(6,5,4)
结尾无空行
```
### 思路
用```map<int,map<int>>```储存，注意内层迭代器表示为```itt.first```

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, e;
    cin >> n >> e;
    map<int, map<int, int>> m;
    int a, b, c;
    int t;
    for (int i = 0; i < e; ++i)
    {
        cin >> a >> b >> c;
        if (!i)
        {
            t = a;
        }
        m[a][b] = c;
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ":";
        for (auto itt : it->second)
        {
            cout << "(" << it->first << "," << itt.first << "," << itt.second << ")";
        }
        cout << endl;
    }
    return 0;
}
```
## 7-2 图的删边操作
### 题面
请编写程序对给定的有向图删除若干条边。有向图中包含n个顶点，编号为0至n-1。
**输入格式:**
输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过1000。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值。各边并非按端点编号顺序排列。随后一行为一个整数k，表示删除的边的条数，接下来k行，每行为2个非负整数a、b，表示待删除的边为a->b。保证删除的边一定在原图中。
**输出格式:**
输出执行删边操作之后的图。每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，表示有向边a->b的权值为w，a引出的多条边按编号b的递增序排列。若某顶点没有引出边，则不输出。
**输入样例:**
在这里给出一组输入。例如：
```
7 7
0 1 5
0 3 7
0 6 6
1 2 4
2 5 1
3 5 3
6 5 4
2
2 5
0 1
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
0:(0,3,7)(0,6,6)
1:(1,2,4)
3:(3,5,3)
6:(6,5,4)
结尾无空行
```
### 思路
输入a与b后先删内层map，如果外层map空则继续删除外层map，和上题储存输出方法相同

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, e;
    cin >> n >> e;
    map<int, map<int, int>> m;
    int a, b, c;
    int t;
    for (int i = 0; i < e; ++i)
    {
        cin >> a >> b >> c;
        if (!i)
        {
            t = a;
        }
        m[a][b] = c;
    }
    int d;
    cin >> d;
    // map<int, int> temp;
    for (int i = 0; i < d; ++i)
    {
        cin >> a >> b;
        // auto delita = m.find(a);
        // temp = delita->second;
        // auto delitb = temp.find(b);
        m[a].erase(b);
        if (!m[a].size())
        {
            m.erase(a);
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ":";
        for (auto itt : it->second)
        {
            cout << "(" << it->first << "," << itt.first << "," << itt.second << ")";
        }
        cout << endl;
    }
    return 0;
}

```

## 7-3 递增子序列
### 题面
给你一个长度为n(1<=n<=15)的整数数组 nums ，0<=nums[i]<=100。找出并打印所有该数组中不同的递增子序列的个数sum，递增子序列中至少有两个元素 。
如出现两个整数相等，也可以视作递增序列的一种特殊情况。例如：
n=4,nums = [4,6,7,7]
满足条件的序列：[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]
sum=8
**输入格式:**
第一行中给出n
第二行为nums元素，空格隔开
**输出格式:**
一个整数sum
**输入样例:**
```
4
4 6 7 7
结尾无空行
```
**输出样例:**
```
8
结尾无空行
```

### 思路
本题使用dfs算法来解决，从数组的第一个元素开始先找到最长递增序列，把这个序列加入集合后向前逐步回溯较短的递增序列，并入集合。
当以第一个元素为首的所有递增序列都找出来后，再从第二个元素开始寻找递增序列，以此类推。
在写代码的时候要注意题目中的一些限制条件，比如说序列的长度至少为2，以及存在元素相等的时候条件的判定。
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int n;
int pre[15], in[15];
void post(int root, int l, int r)
{
    if (l > r)
    {
        return;
    }
    int i = l;
    while (i != r && in[i] != pre[root])
    {
        ++i;
    }
    post(root + 1, l, i - 1);
    post(root + 1 + i - l, i + 1, r);
    cout << pre[root] << " ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in[i];
    }
    post(0, 0, n - 1);
    return 0;
}
```


## 7-4 岛屿数量
### 题面
给你一个由 1（陆地）和 0（水）组成的n*m的二维网格，请你计算网格中岛屿的数量num。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。例如

例	例	例
0	0	0
0	1	0
0	0	1

此为两个岛屿

此外，你可以假设该网格的四条边均被水包围。1<=n,m<=100
**输入格式:**
第一行中给出网格长宽n,m 接下来的n行表示网格情况
**输出格式:**
岛屿个数num
**输入样例:**
```
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
结尾无空行
```
**输出样例:**

```
3
结尾无空行
```
### 思路
从G\[0][0]开始找岛(1)，遇到岛之后上下左右遍历找连续的岛，每访问过一个就把岛置为水(0)，cnt计数输出
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 105
bool G[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
void dfs(int x, int y)
{
    G[x][y] = 0;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if ((0 <= tx && tx < n) && (0 <= ty && ty < m) && G[tx][ty])
        {
            dfs(tx, ty);
        }
    }
}
int search()
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (G[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    scanf("%d %d", &n, &m);
    memset(G, 0, sizeof(G));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &G[i][j]);
        }
    }
    printf("%d\n", search());

    return 0;
}
```

## 7-6 最小支撑树
### 题面
给定一个包含n个顶点的正权无向图，编号为1至n。请编写程序求出其最小支撑树，并计算其边权之和。
**输入格式:**
输入包含多组数据。每组数据第一行为2个整数n和e，均不超过1500，分别表示图的顶点数和边数。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值，不超过100。各边并非按端点编号顺序排列。
**输出格式:**
对于每组数据，若存在最小支撑树则输出一个整数，为最小支撑树各边权值之和；若不存在最小支撑树，则输出“There is no minimum spanning tree.”。
**输入样例:**
```
4 5
1 2 1
1 4 1
2 4 5
2 3 1
3 4 8
4 2
1 2 1
3 4 8
结尾无空行
```
**输出样例:**
```
3
There is no minimum spanning tree.
结尾无空行
```

### 思路
本题使用kruskal算法，用并查集查询是否有环，计算连通子块数目，判断是否能成最小生成树。最后遍历结点计算已生成的树的最小权值。
### 代码
```c++
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
```
## 7-8 排列论文
### 题面
给定编号为1至n的n篇论文，以及m个形如d, u (1≤d,u≤n,d

=u)的引用关系，表示论文论文d中定义的一个名词在论文u中被引用。现在要对这n篇论文重新排列，排列方案须满足如下要求：一篇论文引用的名词必须在排在他前面的论文中被定义过。

请编写程序粗略计算都有多少种满足要求的方案，如果无满足要求的方案则输出0，如果有唯一方案则输出1，如果有多种方案则输出2。
**输入格式:**
输入包含多组数据，每组数据第一行为两个正整数n和m，分别表示论文篇数和引用关系数，均不超过100。接下来m行表示论文引用关系，每行为空格间隔的2个正整数d和u，表示论文论文d中定义的一个名词在论文u中被引用。
**输出格式:**
对于每组数据输出一个整数：无满足要求的排列方案则输出0，如果有唯一方案则输出1，如果有多种方案则输出2。
**输入样例:**
```
5 4
1 5
5 2
3 2
4 3
5 4
3 1
4 2
1 5
5 4
结尾无空行
```
**输出样例:**
```
2
1
结尾无空行
```
### 思路
拓扑排序，图存入邻接链表。定义topo函数判断是否能成拓扑序。定义degflag，统计初始状态下入度为0的结点数目。若能成拓扑序且degflag为1则只有一个拓扑序，若degflag大于1则有多个拓扑序
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int deg[105] = {0}, s[105] = {0};
int degflag = 0;
vector<vector<int>> a;
bool topo(int n)
{
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!deg[i])
        {
            q.push(i);
            degflag++;
        }
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        s[cnt++] = t;
        for (int i : a[t])
        {
            deg[i]--;
            if (!deg[i])
            {
                q.push(i);
            }
        }
    }
    return cnt == n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int d, u;
    for (int i = 0; i <= 104; ++i)
    {
        a.push_back(vector<int>());
    }
    while (cin >> n >> m)
    {
        memset(deg, 0, sizeof(deg));
        memset(s, 0, sizeof(s));

        for (int i = 0; i < m; ++i)
        {
            cin >> d >> u;
            a[d].push_back(u);
            deg[u]++;
            // cout << "a[d][u] = " << a[d] << endl;
        }
        bool flag = topo(n);
        // cout << "topo(n) = " << flag << endl;
        // cout << "degflag = " << degflag << endl;
        if (!flag)
        {
            cout << 0 << endl;
        }
        else if (flag && degflag != 1)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        for (int i = 0; i <= n; ++i)
        {
            a[i].clear();
        }
        degflag = 0;
    }
    return 0;
}
```