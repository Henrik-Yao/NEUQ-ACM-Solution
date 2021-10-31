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