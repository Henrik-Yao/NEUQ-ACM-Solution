# winter-day04题解
### 7-1很简单的最小路径问题，可以通过弗洛伊德算法进行模拟。
```C++
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f3f
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;
typedef pair<__int128, int> PII;

inline __int128 read(){
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void print(__int128 x){
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int h[N], e[M], ne[M], idx;
int h2[N], e2[M], ne2[M], idx2;
__int128 w1[M], w2[M];
__int128 val[N];
int n, m, q;
__int128 d1[N], d2[N];
bool st[N];

void add(int a, int b, __int128 x)
{
    e[idx] = b, w1[idx] = x, ne[idx] = h[a], h[a] = idx++;
}
void add2(int a, int b, __int128 y)
{
    e2[idx2] = b, w2[idx2] = y, ne2[idx2] = h2[a], h2[a] = idx2++;
}

void dij1()
{
    memset(d1, 0x3f, sizeof(d1));
    d1[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if(st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (d1[j] > t.first + w1[i])
            {
                d1[j] = t.first + w1[i];
                heap.push({d1[j], j});
            }
        }
    }
}

void dij2()
{
    memset(st, 0, sizeof(st));
    memset(d2, 0x3f, sizeof(d2));
    d2[n] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, n});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if(st[ver]) continue;
        st[ver] = true;

        for (int i = h2[ver]; ~i; i = ne2[i])
        {
            int j = e2[i];
            if (d2[j] > t.first + w2[i])
            {
                d2[j] = t.first + w2[i];
                heap.push({d2[j], j});
            }
        }
    }
}


int main()
{
    memset(h, -1, sizeof(h));
    memset(h2, -1, sizeof(h2));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m;i++)
    {
        int u, v;
        __int128 a, b;
        scanf("%d%d", &u, &v);
        a = read();
        b = read();
        if (u == v)
            continue;
        add(u, v, a);
        add2(v, u, b);
    }
    for (int i = 1; i <= n;i++)
    {
        val[i] = read();
    }
    dij1();
    dij2();

    set<PII> s;

    for (int i = 1; i <= n;i++)
    {
        if (d1[i] >= INF || d2[i] >= INF) continue;
        s.insert({d1[i] + ((d2[i] + val[i] - 1) / val[i]), i});
    }
    /*puts("");

    __int128 minv = INF;
    int t;
    for (int i = 1; i <= n;i++)
    {
        if (d1[i] >= INF || d2[i] >= INF) continue;
        if (minv > d1[i] + ((d2[i] + val[i] - 1) / val[i]))
        {
            minv = d1[i] + ((d2[i] + val[i] - 1) / val[i]);
            t = i;
            //print(maxv);
            //puts("");
        }
    }*/
    /*for (int i = 1; i <= n;i++)
    {
        print(d1[i]);
        cout << ' ';
        print(d2[i]);
        puts("");
    }*/

    for (int i = 0; i < q; i++)
    {
        int x;
        __int128 y;
        scanf("%d", &x);
        y = read();
        

        if (d1[x] >= INF || d2[x] >= INF)
        {
            auto x = s.begin();
            print(x->first);
        }

        else
        {
            s.erase({d1[x] + ((d2[x] + val[x] - 1) / val[x]), x});
            val[x] = y;
            s.insert({d1[x] + ((d2[x] + val[x] - 1) / val[x]), x});
            auto x = s.begin();
            print(x->first);
        }

        puts("");
    }
    return 0;
}
```
### 7-2 路由器
也可通过弗洛伊德算法进行模拟。
```C++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; // n个路由器,m次询问
    while (cin >> n >> m)
    {
        int map[100][100];
        memset(map, 0x3f, sizeof(map)); //弗洛伊德算法初始化值为0x3f，0x7f太大，会溢出
        for (int i = 0; i < n; i++)
        {
            int z, num;
            cin >> z >> num;
            for (int j = 0; j < num; j++)
            {
                int remp;
                cin >> remp;
                map[i][remp] = 1; //每跳一格是为权值为1
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (i == j)
                {
                    map[i][j] = 0;
                }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (map[i][j] > map[i][k] + map[k][j])
                    {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int remp1, remp2;
            cin >> remp1 >> remp2;
            if (map[remp1][remp2] >= 100)
                cout << "connection impossible" << endl;
            else
                cout << map[remp1][remp2] << endl;
        }
    }

    return 0;
}
```
### 7-3 最短路径之Dijkstra
迪杰斯特拉算法，通过每找到一个入度最低的点将其 标为白点，从而对其他蓝点进行更改标记.
```C++
#include <bits/stdc++.h>
using namespace std;
// Dijkstra 迪杰斯特拉算法
int path[3000]; //记录路径
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
   int n, e;            //顶点数和边数
    int G[3000][3000]; //构建图
 
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
    int dis[5000]; //起点到各点的最短距离
    memset(path, -1, sizeof path);
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0; //标记起点入度为零
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

        } // 每次寻找dis最小的节点切入
        if (u == -1)
            break;
        visit[u] = 1;
        for (int j = 0; j < n; j++)
        {
            if (G[u][j] == 0x3f3f3f3f)
                continue;
            if (dis[u] + G[u][j] < dis[j]) //每次以当前入度最小的点为中心，来更新其他点的入度
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
```
### 7-4 最短路径之Floyd
弗洛伊德问题打印，关键是构建一个类似于迪杰斯特拉算法的前驱数组，我用的时后去数组，效果相同。
```C++
#include <bits/stdc++.h>
using namespace std;
int map1[1000][1000];
int path[1000][1000];
//floyed 算法实现且路径打印
//path 数组记录
int main()
{
    int n, m; // n为顶点数,m为边数
    cin >> n >> m;
    memset(map1, 0x3f, sizeof(map1));
    for (int i = 0; i < m; i++)
    {
        int remp1, remp2, remp3;
        cin >> remp1 >> remp2 >> remp3;
        map1[remp1][remp2] = remp3;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j] = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == j)
            {
                map1[i][j] = 0;
            }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map1[i][j] > map1[i][k] + map1[k][j])
                {
                    map1[i][j] = map1[i][k] + map1[k][j];
                    path[i][j] =path[i][k];
                }
            }
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<map1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < 2; i++)
    {
        int remp1, remp2;
        cin >> remp1 >> remp2;
        if(remp1==remp2)
        cout<<remp1<<"->"<<remp2<<":"<<0<<endl;
        else
        {
            int start=remp1;
            int end=remp2;
            cout<<start;
            while(start!=end)
            {
                cout<<"->"<<path[start][end];
                start=path[start][end];
            }
            if(map1[remp1][remp2]<9998)
            cout<<":"<<map1[remp1][remp2]<<endl;
            else
            cout<<":"<<-1<<endl;
        }
    }
    int max_distace=-9998;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map1[i][j]>max_distace&&(map1[i][j]<9998&&map1[i][j]>-9998))
            {
                max_distace=map1[i][j];
            }//找到这个最大距离
        }
    }
    int max_start=-99998,max_end=-99998;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(max_distace==map1[i][j])
            {
                max_start=i;
                max_end=j;
            }
        }
    }
    int remp_start=max_start,remp_end=max_end;
    if(max_start==max_end)
    cout<<max_start<<"->"<<max_end<<endl;
    else 
    {
        cout<<max_start;
        while(max_start!=max_end)
        {
            cout<<"->"<<path[max_start][max_end];
            max_start=path[max_start][max_end];
        }
        cout<<":"<<map1[remp_start][remp_end];
    }
    return 0;
}
```
### 7-5 迷宫变种-最短路径
关键是回溯！回溯！回溯！
贪心+迪杰斯特拉
```C++
#include <bits/stdc++.h>
using namespace std;
int l,w;                //l长，w宽
int start_x, start_y, end_x, end_y; //起点，终点
int map1[100][100]; //记录图
int dis[100][100];  //记录起点到任意一点的距离(能量耗值)
int ans[100][2];      //存最终答案的数组坐标
int path[100][2];     //存到所有点的通用路径(暂时容器)
int dirx[4]={0,0,-1,1};
int diry[4]={1,-1,0,0}; //位移变量
int cnt=0;              //记录各条路的路线经过点数
int sum=0;              //记录最终答案的经过点数
void search(int x,int y)
{
    if(x==end_x&&y==end_y)
    {
        for(int i=0;i<cnt;i++)
        {
            ans[i][0]=path[i][0];
            ans[i][1]=path[i][1];//路径配置成功！将路径拷贝入最终路径中
        }
        sum=cnt;    //路径数赋值
        return;
    }
    for(int i=0;i<4;i++)
    {
        int dx=x+dirx[i];
        int dy=y+diry[i];
        if(map1[dx][dy]!=-1&&(dx<l&&dx>=0)&&(dy<=w&&dy>=0)&&dis[x][y]+map1[dx][dy]<dis[dx][dy])
        {
            //若满足，说明是可以选择的中介点
            dis[dx][dy]=dis[x][y]+map1[dx][dy];
            path[cnt][0]=dx;
            path[cnt][1]=dy;
            cnt++;
            search(dx,dy);
            cnt--; //关键中的关键！一定要回溯！如果这条路不能到终点，直接一层一层回溯，抛出，重置。
        }
    }
}
int main()
{
    memset(dis,0x3f,sizeof(dis));
    cin >> l >> w;
    cin >> start_x >> start_y >> end_x >> end_y;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> map1[i][j];
        }
    }
    int s=start_x,e=start_y;
    dis[s][e]=map1[s][e];  //将起点先赋入
    path[cnt][0]=s;
    path[cnt][1]=e;      //将起点塞入路径中
    cnt++;
    search(s,e);
    for(int i=sum-1;i>=0;i--)
    cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<")";
    return 0;
}
/*
10 10
3 6 8 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1  2  1  1  1  1  1  5  1 -1
-1  1  9  9  9  1  1 -1  1 -1
-1  1  1  1  1  1  1 -1  1 -1
-1  1 -1 -1 -1 -1 -1 -1  1 -1
-1  1  9  9  9  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  2 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
/*
 --------------------------->x
|从0开始
|
|
|
|
|
|
|
^y
*/
/*


*/
```
