## Winer DAY04-李雨桐

### 7-1 双十一

双十一期间，某著名电商平台“东东”为应对销售高峰，准备在n个城市中再增加一个自营仓库，其要求是该仓库设在n个城市中的某个城市，且距离其他所有城市的最短距离之和最小。请编写程序帮助“东东”找出设立仓库的地点。假定n个城市编号为0至n-1，它们之间至少有一个城市与其他所有城市可及。

### 输入格式:

输入包含多组数据。每组数据第一行为两个正整数n和e，均不超过100。n表示城市数。接下来e行表示两个城市间的距离信息，每行为3个非负整数a、b、c，其中a和b表示两个城市编号，c表示城市间的距离。

提示：可使用EOF判断输入结束。

### 输出格式:

输出为一个整数，表示建立仓库的城市编号，如多个城市满足要求，则输出编号最小者。

### 输入样例:

```in
6 5
0 1 1
0 2 1
0 3 1
0 4 1
0 5 1
4 5
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
```

### 输出样例:

```out
0
1
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

int Map[105][105];

int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        memset(Map,0x3f,sizeof Map);
        for(int i=1;i<=e;i++)
        {
            int from,to,v;
            cin>>from>>to>>v;
            from++,to++;
            if(from==to)
                Map[from][to]=0;
            else
            {
                Map[from][to]=v;
                Map[to][from]=v;
            }
        }

        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(Map[i][j]>Map[i][k]+Map[k][j])
                        Map[i][j]=Map[i][k]+Map[k][j];

        long long dis[105] = {0};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    dis[i] = dis[i] + (long long)Map[i][j];

        long long ans = 0x3f3f3f3f;
        int pos=1;
        for(int i=1;i<=n;i++)
            if(dis[i]<ans)
            {
                ans=dis[i];
                pos = i;
            }

        pos--;
        cout<<pos<<endl;
    }

    return 0;
}

```

----------------------

### 7-2 路由器

快速的信息传送已经成为必须。信息传送工作由位于网络节点上的路由器来实现。每个路由器都维护一个“路由器表”，给出它可以直接到达的路由器编号。很明显，信息传送要求经过的路由器最少（也被称为“跳数”）。对于给出的网络，要求编写程序发现从信息源到目标节点的最佳路线（最少跳数）。假定n个路由器编号为0至n-1，网络中路由器数目不超过200，且至少有2个路由器，每个路由器最多和50个路由器直接相连。

### 输入格式:

输入包含多组测试数据。每组数据输入第一行为整数n和m，表示网络中路由器数。接下来n行表示每个路由器可直接到达的路由器ID列表，每行为一组空格间隔的整数，格式为*i* *k* *v*1 *v*2 ... *v**k*，其中*i*表示路由器编号，*k*为路由器i可直接到达的路由器数，接下来*k*个数 *v*1 *v*2 ... *v**k*表示路由器i可直接到达的路由器编号。接下来m行，表示m组查询，每行两个整数a和b，表示起始路由器和终点路由器编号。

提示：可使用EOF判断输入结束

### 输出格式:

对每组测试数据，输出m行，每行为信息从路由器a传送到路由器b所需经过的最小跳数，如果不可能进行信息传送（起始路由器和终点路由器不连通），则输出“connection impossible”。

### 输入样例:

```in
6 2
0 5 1 2 3 4 5
1 0
2 0
3 0
4 0
5 0
0 2
1 2
4 2
0 2 1 2
1 2 2 3
2 1 3 
3 1 2
0 3
1 0
```

### 输出样例:

```out
1
connection impossible
2
connection impossible
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

#define MAXL 100005
typedef pair<int, int> pir;
vector<bool> book;

void dijkstra(int source,int n,vector<vector<int>> graph,int des);

int main()
{
	int n,m;
	while(cin>>n>>m)
    {
		book = vector<bool>(n, false);
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for(int i=0;i<n;i++)
		{
			int from,len,to;
			cin>>from>>len;
			for(int j=0;j<len;j++)
			{
				cin>>to;
				graph[from][to]=1;
			}
		}
		int source,destination;
		for(int k=0;k<m;k++)
		{
			cin>>source>>destination;
			dijkstra(source,n,graph,destination);
		}
	}
	return 0;
}


void dijkstra(int source,int n,vector<vector<int>> graph,int des)
{
	vector<bool> book(n,false);
	vector<int> dis(n,INT_MAX);
	priority_queue<pir,vector<pir>,greater<pir>> pq;
	pq.push(pir(0,source));
	dis[source]=0;
	while( !pq.empty() )
    {
		int now = pq.top().second;
		pq.pop();
		if(book[now])
            continue;
		book[now]=true;

		for(int i=0;i<n;i++)
        {
			if(graph[now][i]&&!book[i])
			{
				if(dis[i]>dis[now]+graph[now][i])
				{
					dis[i]=dis[now]+graph[now][i];
					pq.push(pir(dis[i],i));
				}
			}
		}
	}
	if(dis[des]!=INT_MAX)
	cout<<dis[des]<<endl;
	else
        cout<<"connection impossible"<<endl;

}

```

------------------------

### 7-3 最短路径之Dijkstra

本题目要求通过读入无向网的边的信息（省略了各顶点的信息，仅用顶点编号来表示），构造图，并利用Dijkstra算法，求出指定源点到其它各点的最短路径。

### 输入样例:

第一行，两个整数，顶点数vN和边数eN。 以后若干行，是相关边的信息，无向图的边是对称的，只输入一半的边（小编号到大编号的，间以空格），最后两行各一个整数，前一个指定源点，后一个指定的查询的终到点。 （注意，示例中34条边，只输入了17条边的信息）

```in
10 34
0 1 2
0 3 5
1 2 5
1 3 2
2 4 8
2 5 4
3 5 4
3 6 2
4 7 5
4 5 2
5 6 3
5 7 9
5 8 7
6 8 7
7 8 3
7 9 4
8 9 8
0
8结尾无空行
```

### 输出样例:

在一行中输出从源点到指定终点的短路径及代价，注意：所有符号均为西文符号。

```out
0-->1-->3-->6-->8:13



结尾无空行
```

### 代码：

```c++
#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int v,l;
};

int n,e,start,stop;
vector <Node> v[1005];

int dist[1005];
int path[1005];
int visit[1005];

void Dijkstra(int start)
{
	fill(dist,dist+1005,10005);
	dist[start]=0;
	for(int i=0;i<n;i++)
        {
		int u=-1,mini =10005;
		for(int j=0;j<n;j++)
		{
			if(visit[j]==0&&dist[j]<mini)
			{
				mini=dist[j];
				u=j;
			}
		}
		if(u == -1)
            break;
		visit[u]=1;
		for (int j=0;j<v[u].size();j++)
		{
            int x = v[u][j].v;
            if (visit[x]==0&&dist[u]+v[u][j].l<dist[x])
            {
                dist[x]=dist[u]+v[u][j].l;
                path[x]=u;
            }
        }
	}
}

int main()
{
	cin>>n>>e;
    for (int i=0;i<e/2;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;

        v[a].push_back(Node{b, c});
        v[b].push_back(Node{a, c});
    }
    cin>>start>>stop;
    if (start == stop)
    {
        printf("%d-->%d:0",start,start);
        return 0;
    }
    Dijkstra(start);
    vector <int> ve;
    int x = stop;
    while (x!=start)
    {
        ve.push_back(x);
        x=path[x];
    }
    cout<<start;
    for (int i=ve.size()-1;i>=0;i--)
        cout<<"-->"<<ve[i];
    cout<<":"<<dist[stop];
}



```

-----------------------

### 7-5 迷宫变种-最短路径

下面图示表示一个迷宫，四周为-1表示围墙,内部为-1表示障碍,权 值1、2、5、9表示经过需要消耗的能量代价。请找出从入口(3,6)到出口(8,8),老鼠消耗能量最小的路径(注意本题是四个方向的迷宫)

![迷宫.png](https://images.ptausercontent.com/650cb5b1-29b9-40b9-8927-13a4d1849cf3.png)

### 输入格式:

第一行：迷宫的大小m n ，分别表示迷宫的长和高 第二行：入口和出口 其余行：迷宫的矩阵表示 提示：用65535为无穷大

### 输出格式:

输出为老鼠消耗能量最小的路径，以逆序输出

### 输入样例:

在这里给出一组输入。例如：

```in
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
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
(8 8)(7 8)(6 8)(5 8)(4 8)(3 8)(2 8)(1 8)(1 7)(1 6)(2 6)(3 6)



结尾无空行
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007
typedef pair<int, int> pir;
struct Point
{
	int x, y, val;
	int fromx, fromy;
	Point(int _x, int _y, int _val) : x(_x), y(_y), val(_val)
	{ }
	bool operator < (Point t) const{
		return val > t.val;
	}
};

struct cmp1
{
	bool operator() (const Point *a,const Point *b) const
	{
		return a->val > b->val;
	}
};

int main()
{
	int m,n,x1,y1,x2,y2;
	cin>>m>>n;
	vector <vector<int>> graph(m, vector<int>(n));
	cin>>x1>>y1>>x2>>y2;
	for(int i=0;i<m;i++)
    {
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	}
	vector<vector<pir>> prev(m, vector<pir>(n));
	vector<vector<bool>> book(m, vector<bool>(n, false));
	vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
	priority_queue<Point*, vector<Point*>, cmp1> pq;
	Point* p = new Point(x1, y1, graph[x1][y1]);

	pq.push(p);
	dis[x1][y1] = 0;

	while(!pq.empty())
    {
		Point* now = pq.top();
		pq.pop();
		int x, y;
		x = now->x, y = now->y;

		if(book[x][y])
            continue;
		book[x][y]=true;

		if(graph[x+1][y] != -1 && !book[x+1][y])
        {
			if(dis[now->x][now->y] + graph[x+1][y] < dis[x+1][y])
			{
				dis[x+1][y] = dis[now->x][now->y] + graph[x+1][y];
				Point* p = new Point(x+1, y, dis[x+1][y]);
				pq.push(p);
				prev[x+1][y] = pir(x, y);
			}
		}
		if(graph[x-1][y] != -1 && !book[x-1][y])
		{
			if(dis[now->x][now->y] + graph[x-1][y] < dis[x-1][y])
			{
				dis[x-1][y] = dis[now->x][now->y] + graph[x-1][y];
				Point* p = new Point(x-1, y, dis[x-1][y]);
				pq.push(p);
				prev[x-1][y] = pir(x, y);
			}
		}
		if(graph[x][y+1] != -1 && !book[x][y+1])
		{
			if(dis[now->x][now->y] + graph[x][y+1] < dis[x][y+1])
			{
				dis[x][y+1] = dis[now->x][now->y] + graph[x][y+1];
				Point* p = new Point(x, y+1, dis[x][y+1]);
				pq.push(p);
				prev[x][y+1] = pir(x, y);
			}
		}
		if(graph[x][y-1] != -1 && !book[x][y-1])
		{
			if(dis[now->x][now->y] + graph[x][y-1] < dis[x][y-1])
			{
				dis[x][y-1] = dis[now->x][now->y] + graph[x][y-1];
				Point* p = new Point(x, y-1, dis[x][y-1]);
				pq.push(p);
				prev[x][y-1] = pir(x, y);
			}
		}
	}
	int P, Q;
	cout<<"("<<x2<<" "<<y2<<")";
	while(1)
    {
		P=x2,Q=y2;
		x2=prev[P][Q].first;
		y2=prev[P][Q].second;
		cout<<"("<<x2<<" "<<y2<< ")";
		if(x2==x1&&y2==y1)
            break;
	}
    
    return 0;
}


```

