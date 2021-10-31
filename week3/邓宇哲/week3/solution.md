# 生化危机
设城市类 ，储存是否被搜索过、是否安全、所连接的城市、连接城市的数量等信息，深度搜索返回bool类型。逻辑较为精密。
~~~c++
#include <iostream>
using namespace std;
struct city
{
    bool done = 0;
    bool safe = 0;
    int conect[101] = {0};
    int conectnum = 0;
};
bool dfs(city a[], int start, int end);
main()
{
    int m, n, k;
    cin >> m >> n >> k;
    city a[m];
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        a[no].safe = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int d, b;
        cin >> d >> b;
        a[d].conect[a[d].conectnum] = b;
        a[d].conectnum++;
        a[b].conect[a[b].conectnum] = d;
        a[b].conectnum++;
    }
    int there, that;
    cin >> there >> that;
    if (!(a[that].safe))
    {
        cout << "The city " << that << " is not safe!";
        return 0;
    }
    if (dfs(a, there, that))
    {
        cout << "The city " << that << " can arrive safely!";
    }
    else
        cout << "The city " << that << " can not arrive safely!";
}
bool dfs(city a[], int start, int end)
{
    if (start == end)
    {
        return true;
    }
    if (a[start].done)
    {
        return false;
    }
    a[start].done = 1;
    for (int i = 0; i < a[start].conectnum; i++)
    {
        if (dfs(a, a[start].conect[i], end))
        {
            return true;
        }
    }
    return false;
}
~~~
# 那就别担心了
设命题类，储存所能推出的命题的编号、所能推出的命题的数量、有没有被推过、到结论有多少种推法（便于快速调值以减少递归）。
```c++
#include <cstring>
#include <iostream>
using namespace std;
long long sum = 0;
bool exist = 1;
struct mingti
{
    long long point[505];
    long long num = 0;
    bool done = 0;
    int ways = 0;
};
mingti a[505];
void dfs(long long, long long);
main()
{
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < m; i++)
    {
        long long t, r;
        cin >> t >> r;
        a[t].point[a[t].num] = r;
        a[t].num++;
    }
    long long j, k;
    cin >> j >> k;
    dfs(j, k);
    cout << a[j].ways << ' ';
    if (exist)
    {
        cout << "Yes";
    }
    else
        cout << "No";
}
void dfs(long long n, long long d)
{
    if (n == d)
    {
        a[n].ways++;
        return;
    }
    if (a[n].num == 0)
    {
        exist = 0;
    }
    for (long long i = 0; i < a[n].num; i++)
    {
        if (!(a[n].done))
        {
            a[n].done = 1;
            if (a[a[n].point[i]].ways==0)
            {
                dfs(a[n].point[i], d);
            }
            
            a[n].ways += a[a[n].point[i]].ways;
            a[n].done = 0;
        }
    }
}
```
# 扫雷
设点类，保存是不是雷，值是多少。

先对周围八个点分别进行检查，如果查到雷数值就增加，然后判断是否应该对周围八个点进行深度搜索（数值大于0就要退出，不能搜索）。
~~~c++
#include <iostream>
using namespace std;
struct point
{
    bool lei = 0;
    int value = -1;
};
point a[22][22];
int n, m, k, l, area = 0;
void dfs(int, int);
bool ifout(int, int);
int  main()
{
    cin >> n >> m >> k >> l;
    for (int t = 0; t < k; t++)
    {
        int i, j;

        cin >> i >> j;
        a[i][j].lei = 1;
    }
    for (int t = 0; t < l; t++)
    {
        int i, j;
        cin >> i >> j;
        if (a[i][j].value != -1)
            continue;
        else if (a[i][j].lei)
        {
            cout << "You lose";
            return 0;
        }
        else
        {
            dfs(i, j);
            for (int o = 0; o < n; o++)
            {
                for (int p = 0; p < m; p++)
                {
                    cout << a[o][p].value << ' ';
                }
                cout << endl;
            }
        }
        if (area == m * n - k)
        {
            cout << "You win";
            return 0;
        }
        cout << endl;
    }
    return 0;
}
bool ifout(int i, int j)
{
    return !(i < 0 || j < 0 || i >= n || j >= m);
}
void dfs(int i, int j)
{
    if (a[i][j].value != -1 || !(ifout(i, j)))
    {
        return;
    }
    a[i][j].value = 0;
    area++;
    if (ifout(i + 1, j + 1))
    {
        if (a[i + 1][j + 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i + 1, j))
    {
        if (a[i + 1][j].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i + 1, j - 1))
    {
        if (a[i + 1][j - 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i, j + 1))
    {
        if (a[i][j + 1].lei)
        {
            a[i][j].value++;
        }
       
    }
    if (ifout(i, j - 1))
    {
        if (a[i][j - 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i - 1, j))
    {
        if (a[i - 1][j].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i - 1, j - 1))
    {
        if (a[i - 1][j - 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (ifout(i - 1, j + 1))
    {
        if (a[i - 1][j + 1].lei)
        {
            a[i][j].value++;
        }
        
    }
    if (a[i][j].value > 0)
        return;
    if (ifout(i + 1, j + 1)&&a[i+1][j+1].value==-1)
    {
        dfs(i + 1, j + 1);
    }
    if (ifout(i + 1, j)&&a[i+1][j].value==-1)
    {

        dfs(i + 1, j);
    }
    if (ifout(i + 1, j - 1)&&a[i+1][j-1].value==-1)
    {

        dfs(i + 1, j - 1);
    }
    if (ifout(i, j + 1)&&a[i][j+1].value==-1)
    {

        dfs(i, j + 1);
    }
    if (ifout(i, j - 1)&&a[i][j-1].value==-1)
    {

        dfs(i, j - 1);
    }
    if (ifout(i - 1, j)&&a[i-1][j].value==-1)
    {

        dfs(i - 1, j);
    }
    if (ifout(i - 1, j - 1)&&a[i-1][j-1].value==-1)
    {

        dfs(i - 1, j - 1);
    }
    if (ifout(i - 1, j + 1)&&a[i-1][j+1].value==-1)
    {

        dfs(i - 1, j + 1);
    }
}
~~~
# 01迷宫
代码加了注释，不写了。
~~~c++
#include <cstring>
#include <iostream>
using namespace std;
struct point
{//值、有没有经历过、颜色（连通块编号）
    char value;
    bool done = 0;
    long long color = 1000000-1;//初始化使连通块编号最大。
};
int roomarea = 0,color=0;
point a[1009][1009];
int colors[1000000]={0};//储存 对应连通块大小 的数组，默认的点的连通块编号为1000000-1，储存值为0
int n, m;
void dfs(int, int);
main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> a[i][j].value;
        }
    }
    for (color = 0; color < m; color++)//执行M次，每执行一次，更新连通块编号
    {
        int c, d;
        cin >> c >> d;
        if (colors[a[c][d].color]==0)//如果该点所在的连通块没有大小，即该点未被搜索，就进行如下操作
        {
            dfs(c , d);
            cout << roomarea << endl;
            colors[color] = roomarea;//将此连通块的大小储存起来，以便到时候可以直接查询
            roomarea = 0;//归零以便重新计数
            }
            else    //该点被记录过，直接输出
            cout << colors[a[c][d].color] << endl;
    }
}
void dfs(int i, int j)
{
    if (a[i][j].done)//记录过？
    {
        return;
    }
    roomarea++;//连通块大小增加
    a[i][j].done = 1;//记录！
    a[i][j].color = color;//染色操作，即赋予其连通块编号
    if (a[i][j].value != a[i][j + 1].value && j != n )
        dfs(i, j + 1);
    if (a[i][j].value != a[i + 1][j].value && i != n )
        dfs(i + 1, j);
    if (a[i][j].value != a[i - 1][j].value && i != 1)
        dfs(i - 1, j);
    if (a[i][j].value != a[i][j - 1].value && j != 1)
        dfs(i, j - 1);
    //上下左右搜索
}
~~~