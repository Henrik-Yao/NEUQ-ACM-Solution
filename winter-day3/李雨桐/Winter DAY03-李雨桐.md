## Winter DAY03-李雨桐

### 3-1 图的创建

请编写程序创建一个有向图。有向图中包含n个顶点，编号为0至n-1。

### 输入格式:

输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过20000。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值。各边并非按端点编号顺序排列。

### 输出格式:

按顶点编号递增顺序输出每个顶点引出的边，每个顶点占一行，若某顶点没有引出边，则不输出。每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，表示有向边a->b的权值为w，a引出的多条边按编号b的递增序排列。

### 输入样例:

```in
7 7
0 1 5
0 3 7
0 6 6
1 2 4
2 5 1
3 5 3
6 5 4
```

### 输出样例:

```out
0:(0,1,5)(0,3,7)(0,6,6)
1:(1,2,4)
2:(2,5,1)
3:(3,5,3)
6:(6,5,4)
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pir;
map<int, int> Map[20005];

int n,e;
int a,b,c;

int main()
{

	cin>>n>>e;
	for(int i=0;i<e;i++)
    {
		cin>>a>>b>>c;
		Map[a].insert(pir(b, c));
	}
	for(int i=0;i<n;i++)
	{
		bool flag = false;
		for(auto it : Map[i])
		{
			if(flag==0)
			cout << i << ":";
			flag = true;
			cout<<"("<<i<<","<<it.first<<","<<it.second<<")";
		}
		if(flag==1)
		cout << endl;
	}
}

```

---------------------------

### 3-2 图的删边操作

请编写程序对给定的有向图删除若干条边。有向图中包含n个顶点，编号为0至n-1。

### 输入格式:

输入第一行为两个正整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过1000。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值。各边并非按端点编号顺序排列。随后一行为一个整数k，表示删除的边的条数，接下来k行，每行为2个非负整数a、b，表示待删除的边为a->b。保证删除的边一定在原图中。

### 输出格式:

输出执行删边操作之后的图。每行表示一个顶点引出的所有边，格式为a:(a,b,w)……，表示有向边a->b的权值为w，a引出的多条边按编号b的递增序排列。若某顶点没有引出边，则不输出。

### 输入样例:

```in
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
```

### 输出样例:

```out
0:(0,3,7)(0,6,6)
1:(1,2,4)
3:(3,5,3)
6:(6,5,4)
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin>>n>>m;
	map<int,map<int,int>>MAP;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		MAP[a][b]=c;
	}

	int t;
	cin>>t;

	for (int i=0;i<t;++i)
	{
		int a,b;
		cin>>a>>b;
		MAP[a].erase(b);
	}

	for (auto i:MAP)
	{
		int a=i.first;

		if(!i.second.empty())
            cout<<a<<":";

		for (auto j:i.second)
            cout<<"("<<a<<","<<j.first<<","<<j.second<<")";

		if(i.second.empty()==0)
            cout<< endl;
	}

	return 0;
}

```

--------------------------------

### 3-3 递增子序列

给你一个长度为n(1<=n<=15)的整数数组 nums ，0<=nums[i]<=100。找出并打印所有该数组中不同的递增子序列的个数sum，递增子序列中至少有两个元素 。

如出现两个整数相等，也可以视作递增序列的一种特殊情况。例如：

n=4,nums = [4,6,7,7]

满足条件的序列：[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]

sum=8

### 输入格式:

第一行中给出n

第二行为nums元素，空格隔开

### 输出格式:

一个整数sum

### 输入样例:

在这里给出一组输入。例如：

```in
4
4 6 7 7
结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
8
结尾无空行
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

set <vector<int>> ans;
vector <int> t;
int a[20],n;
void searc(int x)
{

	if (t.size()>=2)
	{
		ans.insert(t);
	}
	for (int i=x;i<n;i++)
	{
		if (t.empty()||a[i]>=t[t.size()-1])
		{
			t.push_back(a[i]);
			searc(i + 1);
			t.pop_back();
		}
		else searc(i + 1);
	}
}
int main()
{

	cin>>n;
	for (int i=0;i<n;i++)
		cin >> a[i];

	searc(0);
	
	cout<<ans.size()<<endl;
	return 0;
}

```

---------------------------------

### 3-4 岛屿数量

给你一个由 1（陆地）和 0（水）组成的n*m的二维网格，请你计算网格中岛屿的数量num。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。例如

| 例   | 例   | 例   |
| ---- | ---- | ---- |
| 0    | 0    | 0    |
| 0    | 1    | 0    |
| 0    | 0    | 1    |

此为两个岛屿

此外，你可以假设该网格的四条边均被水包围。1<=n,m<=100

### 输入格式:

第一行中给出网格长宽n,m 接下来的n行表示网格情况

### 输出格式:

岛屿个数num

### 输入样例:

在这里给出一组输入。例如：

```in
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
3
结尾无空行
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

int a[2005][2005]={0};
int m,n;
int ans = 0;

void solve(int x, int y);

int main()
{

	cin>>m>>n;

	for(int i=1;i<=m;i++)
	{
		for(int j =1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
            {
				solve(i,j);
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}

void solve(int x, int y)
{
	if(x<1||x>m||y<1||y>n||a[x][y]==0)
        return;
	a[x][y]=0;
	solve(x+1,y);
	solve(x-1,y);
	solve(x,y+1);
	solve(x,y-1);
}


```

------------------------------------------

### 3-5 繁忙的都市

城市 C 是一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造。城市 C 的道路是这样分布的：城市中有 *n* 个交叉路口，有些交叉路口之间有道路相连，两个交叉路口之间最多有一条道路相连接。这些道路是双向的，且把所有的交叉路口直接或间接的连接起来了。每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造。但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：

1. 改造的那些道路能够把所有的交叉路口直接或间接的连通起来。
2. 在满足要求 (1) 的情况下，改造的道路尽量少。
3. 在满足要求 (1)、(2) 的情况下，改造的那些道路中分值最大的道路分值尽量小。

任务：作为市规划局的你，应当作出最佳的决策，选择那些道路应当被修建。

### 输入格式:

第一行有两个整数 *n*,*m* 表示城市有 *n* 个交叉路口，*m* 条道路。

接下来 *m* 行是对每条道路的描述，*u*,*v*,*c* 表示交叉路口 *u* 和 *v* 之间有道路相连，分值为 *c* 。

### 输出格式:

两个整数 *s*,*ma**x*，表示你选出了几条道路，分值最大的那条道路的分值是多少。

### 输入样例:

```in
4 5
1 2 3
1 4 5
2 4 7
2 3 6
3 4 8结尾无空行
```

### 输出样例:

```out
3 6



结尾无空行
```

### 数据范围与提示

1≤*n*≤300,1≤*c*≤10000

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

struct dushi
{
    int u;
    int v;
    int d;
};

int n,m,maxi,far[505];
dushi a[90005];

int searc(const dushi &x,const dushi &y)
{
    if (x.d<y.d)
        return 1;
    else
        return 0;
}
int findfar(int x)
{
    if (far[x]!=x)
        x=findfar(far[x]);
    return
        far[x];
}
void gener(int x,int y)
{
    int p=findfar(x),q=findfar(y);
    if (p!=q)
        far[p]=q;
}

int main()
{
    cin>>n>>m;

    for (int i=1;i<=m;i++)
        cin>>a[i].u>>a[i].v>>a[i].d;
    for (int i=1;i<=n;i++)
        far[i]=i;

    cout<<n-1<<' ';
    sort(a+1,a+m+1,searc);

    int temp=0;
    for (int i=1;i<=m;i++)
        {
            if (findfar(a[i].u)!=findfar(a[i].v))
                {
                    gener(a[i].u,a[i].v);
                    temp++;
                    maxi=max(maxi,a[i].d);
                }

            if (temp==n-1)
                break;
        }

    cout<<maxi;
    return 0;
}

```

-------------------------------

### 3-6 最小支撑树

给定一个包含n个顶点的正权无向图，编号为1至n。请编写程序求出其最小支撑树，并计算其边权之和。

### 输入格式:

**输入包含多组数据。**每组数据第一行为2个整数n和e，均不超过1500，分别表示图的顶点数和边数。接下来e行表示每条边的信息，每行为3个非负整数a、b、c，其中a和b表示该边的端点编号，c表示权值，不超过100。各边并非按端点编号顺序排列。

### 输出格式:

对于每组数据，若存在最小支撑树则输出一个整数，为最小支撑树各边权值之和；若不存在最小支撑树，则输出“There is no minimum spanning tree.”。

### 输入样例:

```in
4 5
1 2 1
1 4 1
2 4 5
2 3 1
3 4 8
4 2
1 2 1
3 4 8
```

### 输出样例:

```out
3
There is no minimum spanning tree.
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int u;
    int v;
    int w;
} Edge;

int f[205];

bool cmp(Edge e1, Edge e2)
{
    return e1.w<e2.w;
}

void init()
{
    for (int i=0;i<=200;i++)
        f[i] = i;
}

int searc(int x)
{
    if (x==f[x])
        return x;
    return f[x] = searc(f[x]);
}

int mergeflag(int x, int y)
{
    int a=searc(x);
    int b=searc(y);
    if (a!=b)
{
        f[b] = a;
        return 1;
    }
    return 0;
}

int main()
{
    int n,e;

    while (cin>>n>>e)
        {
        Edge edge[e];

        for (int i=0;i<=200;i++)
            f[i] = i;

        for (int i=0;i<e;i++)
        {
            cin>>edge[i].u>>edge[i].v>>edge[i].w;
        }

        sort(edge,edge+e,cmp);

        int num=0,sum=0;
        for (int i=0;i<e;i++)
        {
            if (mergeflag(edge[i].u,edge[i].v))
            {
                num++;
                sum+=edge[i].w;
            }
            if (num==n-1)
                break;
        }
        if (num==n-1)
            cout<<sum<<endl;
        else
            cout<<"There is no minimum spanning tree."<<endl;
    }

    return 0;
}

```

----------------------

