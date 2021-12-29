## 7-1 双十一

双十一期间，某著名电商平台“东东”为应对销售高峰，准备在n个城市中再增加一个自营仓库，其要求是该仓库设在n个城市中的某个城市，且距离其他所有城市的最短距离之和最小。请编写程序帮助“东东”找出设立仓库的地点。假定n个城市编号为0至n-1，它们之间至少有一个城市与其他所有城市可及。

~~一开始有一种冲动，dfs全上一遍然后比较。。。~~

想通了之后觉得自己真的蠢

~~~#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int ma[101][101];
int main()
{
    int n, e;
    while (cin>>n,cin>>e)
    {
        memset(ma, 0x3f, sizeof ma);
        for (int i = 1; i <= e; i++)
        {
            int q, p, v;
            cin >> q >> p >> v;
            q++, p++;
            if (q == p) ma[q][p] = 0;
            else
            {
                ma[q][p] = v;
                ma[p][q] = v;
            }
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    if (ma[i][j] > ma[i][k] + ma[k][j])
                        ma[i][j] = ma[i][k] + ma[k][j];

        long long dis[101] = { 0 };
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j) 
                    dis[i] = dis[i] + (long long)ma[i][j];

        long long ans = 99999999999;
        int pos = 1;
        for (int i = 1; i <= n; i++)
            if (dis[i] < ans)
            {
                ans = dis[i]; pos = i;
            }
        pos--;
        cout << pos << endl;
    }
    return 0;
}
~~~

## 7-2 路由器

快速的信息传送已经成为必须。信息传送工作由位于网络节点上的路由器来实现。每个路由器都维护一个“路由器表”，给出它可以直接到达的路由器编号。很明显，信息传送要求经过的路由器最少（也被称为“跳数”）。对于给出的网络，要求编写程序发现从信息源到目标节点的最佳路线（最少跳数）。假定n个路由器编号为0至n-1，网络中路由器数目不超过200，且至少有2个路由器，每个路由器最多和50个路由器直接相连。

**dfs**

~~~#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int a, b;
int en = 99999;
bool vis[201];
vector<int> ma[201];
void dfs(int now, int cs)
{
	if (vis[now])return;
	if (now == b) { en = min(en, cs); return; }
	vis[now] = 1;
	for (auto lsz : ma[now])
		dfs(lsz,cs+1);
	vis[now] = 0;
}

int main() 
{
	int n;
	while ((cin >> n), n != EOF)
	{
		memset(vis, 0, 201);
		for (int i=0;i<201;i++)
			ma[i].clear();
		int m; cin >> m;
		while (n--)
		{
			int i, k; cin >> i >> k;
			while (k--)
			{
				int q;
				cin >> q;
				ma[i].push_back(q);
			}
		}
		while (m--)
		{
			en = 99999;
			cin >> a >> b;
			dfs(a, 0);

			if (en == 99999)cout << "connection impossible" << endl;
			else cout << en << endl;
		}
	}
}
~~~

## 7-3 最短路径之Dijkstra

本题目要求通过读入无向网的边的信息（省略了各顶点的信息，仅用顶点编号来表示），构造图，并利用Dijkstra算法，求出指定源点到其它各点的最短路径。

**~~dfs~~**

### **为什么会卡0->0这个数据！！！！！！**

~~~#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

bool vis[10001];
vector<int> nev[10001];
map<string, int>ma;
int dj[10001];//初始地去往某地的代价
int cs, en;
string path="";


string str(int n)
{
	return to_string(n);
}

void dfs(int now,string o,int xh)
{
	if (vis[now])return;
	if (dj[now] < xh)return;
	dj[now] = xh;
	if (now == en) { path = o; return; }
	vis[now] = 1;
	for (auto lsz : nev[now])
		dfs(lsz, o + "-->" + str(lsz), xh + ma[str(now) + "-" + str(lsz)]);
	vis[now] = 0;
}

int main()
{
	memset(dj, 999999, 10001);
	int v, e;//顶点数vN和边数eN
	cin >> v >> e;
	for (int i = 0; i < e / 2; i++)
	{
		int q, p, v;
		cin >> q >> p >> v;
		nev[q].push_back(p);
		nev[p].push_back(q);
		ma[str(q) + "-" + str(p)] = v;
		ma[str(p) + "-" + str(q)] = v;
	}
	
	cin >> cs >> en;
	if (cs == en) { cout << cs << "-->" << en << ":" << "0"; return 0; }
	dfs(cs,str(cs),0);
	cout << path;
	cout << ":" << dj[en];
	return 0;
}
~~~

## 7-4 最短路径之Floyd

请缩写程序，实现求有向网的最短路径的Floyd算法，因地点可能够是淡泊湖，宁静楼等等，这里简化成编号，要求能够查询出任意两点（用编号表示）间的最短路径及最小距离。

说明：1）顶点个数上限不超过100；2）距离权值上限不超过9998；

~~~#include <iostream>
#include<string.h>
using namespace std;
int n, m, x, y, z;
int cx = -1, cy = -1;
int ans;
int dis[105][105], ins[105][105], p[105];
void deal(int x, int y)
{
	int k = ins[x][y];
	if (k == -1)
	{
		p[y] = x;
		return;
	}
	deal(k, y);
	deal(x, k);
	return;
}
void out(int x, int y)
{
	if (x == y)
	{
		printf("%d", x);
		return;
	}
	out(x, p[y]);
	printf("->%d", y);
	return;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		dis[i][i] = 0;
		for (int j = i + 1; j < n; j++)
		{
			dis[i][j] = 9999999;
			dis[j][i] = 9999999;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		if (dis[x][y] > z)
		{
			dis[x][y] = z;
			ins[x][y] = -1;
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					ins[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= 2; i++)
	{
		cin >> x >> y;
		if (x == y) printf("%d->%d:0\n", x, y);
		else 
		{
			if (dis[x][y] == 9999999) printf("%d->%d:-1\n", x, y);
			else
			{
				memset(p, 0, sizeof(p));
				deal(x, y);
				out(x, y);
				printf(":%d\n", dis[x][y]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dis[i][j] != 9999999 && dis[i][j] > ans)
			{
				ans = dis[i][j];
				cx = i; cy = j;
			}
		}
	}
	memset(p, 0, sizeof(p));
	if (cx != -1 && cy != -1)
	{
		deal(cx, cy);
		out(cx, cy);
		printf(":%d\n", dis[cx][cy]);
	}
	else 
		printf("\n");
	return 0;
}
~~~

## 7-5 迷宫变种-最短路径

下面图示表示一个迷宫，四周为-1表示围墙,内部为-1表示障碍,权 值1、2、5、9表示经过需要消耗的能量代价。请找出从入口(3,6)到出口(8,8),老鼠消耗能量最小的路径(注意本题是四个方向的迷宫)

**dfs**

~~~//我的评价是，dfs
//摆！
//加一点记忆化思想
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;

string str(int n)
{
	return to_string(n);
}

int m, n;
int rx, ry, cx, cy;
int mg[10001][10001];
int arr[10001][10001];//到达此处消耗的最小能量
bool vis[10001][10001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string path = "";
void dfs(int x, int y,int xh,string o)
{
	if (vis[x][y])return;
	if (xh > arr[x][y])return;
	arr[x][y] = xh;
	if (x == cx && y == cy) { path = o; return; }
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i], xh+mg[x][y], "(" + str(x + dx[i]) + " " + str(y + dy[i]) + ")"+o);
	vis[x][y] = 0;
}

int main() 
{
	cin >> m >> n;
	cin >> rx >> ry >> cx >> cy;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> mg[i][j];
			arr[i][j] = 999999;
			if (mg[i][j] == -1)vis[i][j] = 1;
		}
	dfs(rx, ry, 0,"("+str(rx)+" "+str(ry)+")");
	cout << path;
}
~~~

## **7-6 森森旅游**

不太会，参考https://blog.csdn.net/zstuyyyyccccbbbb/article/details/116107268

