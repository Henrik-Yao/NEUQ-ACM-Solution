## 7-1 图的创建

请编写程序创建一个有向图。有向图中包含n个顶点，编号为0至n-1。

**没什么说的，俩向量成组关联存就行了**

~~总感觉写成结构体反而更麻烦了~~

~~~#include<iostream>
#include <string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> to[20001];
vector<int> we[20001];



int main() 
{
	int n, e; cin >> n >> e;
	while (e--)
	{
		int a, b, c; cin >> a >> b >> c;
		int xb = 0;
		for (auto lsz : to[a])
			if (lsz > b)xb++;
		to[a].insert(to[a].begin() + xb, b);
		we[a].insert(we[a].begin() + xb, c);
	}
	for (int i = 0; i < n; i++)
	{
		if (!to[i].empty())
		{
			printf("%d:", i);
			while (!to[i].empty())
			{
				printf("(%d,%d,%d)", i, to[i].back(), we[i].back());
				to[i].pop_back();
				we[i].pop_back();
			}
			cout << endl;
		}
	}
}
~~~



## 7-2 图的删边操作

请编写程序对给定的有向图删除若干条边。有向图中包含n个顶点，编号为0至n-1。

**在上一题的基础上加了个删除即可**

~~~#include<iostream>
#include <string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> to[20001];
vector<int> we[20001];



int main() 
{
	int n, e; cin >> n >> e;
	while (e--)
	{
		int a, b, c; cin >> a >> b >> c;
		int xb = 0;
		for (auto lsz : to[a])
			if (lsz > b)xb++;
		to[a].insert(to[a].begin() + xb, b);
		we[a].insert(we[a].begin() + xb, c);
	}
	int k; cin >> k;
	while (k--)
	{
		int a, b; cin >> a >> b;
		int xb = 0;
		for (auto lsz : to[a])
		{
			if (lsz == b)break;
			xb++;
		}
		auto t1 = to[a].begin();
		to[a].erase(t1 + xb);
		auto t2 = we[a].begin();
		we[a].erase(t2 + xb);
	}
	for (int i = 0; i < n; i++)
	{
		if (!to[i].empty())
		{
			printf("%d:", i);
			while (!to[i].empty())
			{
				printf("(%d,%d,%d)", i, to[i].back(), we[i].back());
				to[i].pop_back();
				we[i].pop_back();
			}
			cout << endl;
		}
	}
}
~~~



## 7-3 递增子序列

给你一个长度为n(1<=n<=15)的整数数组 nums ，0<=nums[i]<=100。找出并打印所有该数组中不同的递增子序列的个数sum，递增子序列中至少有两个元素 。

如出现两个整数相等，也可以视作递增序列的一种特殊情况。例如：

n=4,nums = [4,6,7,7]

满足条件的序列：[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]

sum=8

**暴力遍历即可，注意重复值**

~~~#include<iostream>
#include <string.h>
#include<vector>
#include<stdlib.h>
#include<map>
#include<string>//to_string
using namespace std;

int gs, n, f; 
map<string, bool> ma;//string为已经出现的增序列（如 4,6,13 ）
int num[21];//一刀99999（划掉）

string str(int a)
{
	return to_string(a);
}

void bl(string o,int i)//o为上一次输出的,i为上一次加入的下标
{
	if (ma[o])return;
	ma[o] = true; gs++;
	for (int j = i + 1; j < n; j++)
	{
		if (num[i] <= num[j])
			bl(o + ',' + str(num[j]), j);
	}

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++)
	{
		if (ma[str(num[i])])f++;
		bl(str(num[i]), i);
	}
	cout << gs + f - n;
}
~~~

## 7-4 岛屿数量

给你一个由 1（陆地）和 0（水）组成的n*m的二维网格，请你计算网格中岛屿的数量num。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

**~~这道题我学dfs的时候是不是见过......~~**

~~~// ?????????????????????这不是dfs????????????????????????
#include<iostream>
using namespace std;
int vis[101][101];//visited
int gs = 0;
int ma[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (!vis[x + dx[i]][y + dy[i]] && ma[x + dx[i]][y + dy[i]])
			dfs(x + dx[i], y + dy[i]);
	
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ma[i][j];
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			if (!vis[x][y] && ma[x][y])
			{
				gs++;
				dfs(x, y);
			}
	cout << gs;
}
~~~



## 7-5 繁忙的都市

城市 C 是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。城市 C 的道路是这样分布的：城市中有 *n* 个交叉路口，有些交叉路口之间有道路相连，两个交叉路口之间最多有一条道路相连接。这些道路是双向的，且把所有的交叉路口直接或间接的连接起来了。每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造。但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：

1. 改造的那些道路能够把所有的交叉路口直接或间接的连通起来。
2. 在满足要求 (1) 的情况下，改造的道路尽量少。
3. 在满足要求 (1)、(2) 的情况下，改造的那些道路中分值最大的道路分值尽量小。

任务：作为市规划局的你，应当作出最佳的决策，选择那些道路应当被修建。

~~~
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct stu 
{
	int u;
	int v;
	int c;
};
vector<stu> v;
int fa[10001];

bool cmp(stu x, stu y) 
{
	return x.c < y.c;
}
int find(int x) 
{
	if (fa[x] == x)
		return x;
	else
		return fa[x] = find(fa[x]);
}

void join(int x, int y) 
{
	int f1 = find(x);
	int f2 = find(y);
	if (f1 != f2)
		fa[f1] = f2;
}

int main() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
	{
		stu x;
		cin >> x.u >> x.v >> x.c;
		v.push_back(x);
	}
	int x = 0, maxx = 0;
	for (int i = 0; i < n; i++)
		fa[i] = i;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < m; i++) 
		if (find(v[i].u) != find(v[i].v)) 
		{
			join(v[i].u, v[i].v);
			if (maxx < v[i].c)
				maxx = v[i].c;
			x++;
		}
	cout << x << " " << maxx;
	return 0;
}
~~~

## 7-6 最小支撑树

给定一个包含n个顶点的正权无向图，编号为1至n。请编写程序求出其最小支撑树，并计算其边权之和。

~~~#include <iostream>
#include<algorithm>
using namespace std;

struct T
{
	int u;//顶点1
	int v;//顶点2 
	int w;//权值 
};//结构体存边的信息 
int a[201];

bool cmp(T edge1, T edge2) //排序用的比较
{
	return edge1.w < edge2.w;
}

int find(int x) 
{//查找
	int r = x;
	while (a[r] != r)
		r = a[r];
	return r;
}

int join(int x, int y) 
{//合并 
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) 
	{
		a[fy] = fx;
		return 1;
	}
	return 0;
}

int main()
{
	int n, e;
	while (cin >> n >> e) 
	{
		T tt[101];
		for (int i = 0; i < 201; i++)
			a[i] = i;
		for (int i = 0; i < e; i++) 
			cin >> tt[i].u >> tt[i].v >> tt[i].w;
		sort(tt, tt + e, cmp); //边按权值从小到大排序 
		int cnt = 0, sum = 0; //边数、权值和
		for (int i = 0; i < e; i++) 
		{
			if (join(tt[i].u, tt[i].v)) 
			{//如果顶点u和v不在一个连通图里
				cnt++;
				sum += tt[i].w;
			}
			if (cnt == n - 1) //边数 = 顶点数-1，找到最小生成树 
				break;
		}
		if (cnt == n - 1)
			cout << sum << endl;
		else cout << "There is no minimum spanning tree." << endl;
	}
	return 0;
}
~~~

## 7-7 特殊最小成本修路

n个城镇之间目前有一些道路连接，但道路都是年久失修的土道。现在政府准备将其中一些土道改造为标准公路，希望标准公路能够将所有城镇连通且总成本最小，**但其中有一个城镇比较特殊，受地形等限制，最多只能有两条标准公路通过该镇**。请编写程序，找出一种满足上述条件的、总成本最小的改造方案，若不存在改造方案，则亦能识别。假定道路是双向的。



## 7-8 排列论文

给定编号为1至n的n篇论文，以及m个形如d, u (1≤*d*,*u*≤*n*,*d*=*u*)的引用关系，表示论文论文d中定义的一个名词在论文u中被引用。现在要对这n篇论文重新排列，排列方案须满足如下要求：一篇论文引用的名词必须在排在他前面的论文中被定义过。

请编写程序粗略计算都有多少种满足要求的方案，如果无满足要求的方案则输出0，如果有唯一方案则输出1，如果有多种方案则输出2。



