# **寒假集训—day3（图）**

## **7-1**

使用链式前向星存图

至于顺序输出，可以在输入时先保存，然后对输入的数据排序，再进行建图

**链式前向星主要代码：**

~~~cpp
struct node
{
	int to,nex,v,pre;
}edge[20005];
int head[20005];
int cnt;
void add(int a,int b,int c)
{
	edge[++cnt].to=b;
	edge[cnt].pre=a;
	edge[cnt].v=c;
	edge[cnt].nex=head[a];
	head[a]=cnt;
}
~~~

edge数组保存的是每一条边的信息，

cnt代表边的编号，

e[cnt].to代表边cnt的终点，e[cnt].pre代表边cnt的起点，e[cnt].val代表边cnt的权值，

nex代表和当边cnt拥有相同起点的另一条边的编号（在遍历时使用）

head[a]数组表示以a为起点的其中一条边的编号（通过该数组开始遍历）

**利用链式前向星遍历图**

~~~cpp
for(int i=1;i<=n;i++)//i代表点的编号
{
    //head[i]:以i为起点的一条边  e[i].nex:另一条以i为起点的边
    for(int j=head[i];j;j=e[i].nex)//从一条以点i为起点的边开始遍历 以i为起点的每一条边
    {
        //操作
    }
}
~~~

AC代码

~~~cpp
#include<bits/stdc++.h>

using namespace std;
int n,e;
struct node
{
	int to,nex,v,pre;
}edge[20005];
int head[20005];
int cnt;
void add(int a,int b,int c)
{
	edge[++cnt].to=b;
	edge[cnt].pre=a;
	edge[cnt].v=c;
	edge[cnt].nex=head[a];
	head[a]=cnt;
}
struct cmpp
{
	int a,b,c;
}x[20005];
bool cmp(cmpp a,cmpp b)
{
	if(a.a<b.a)return true;
	else if(a.a>b.a)return false;
	else if(a.a==b.a)
	{
		if(a.b>b.b)return true;
		else return false;
	}
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>x[i].a>>x[i].b>>x[i].c;
	}
	sort(x+1,x+1+e,cmp);
	for(int i=1;i<=e;i++)
	{
		add(x[i].a,x[i].b,x[i].c);
	}
	for(int i=0;i<n;i++)
	{
		if(head[i]!=0)
		{
			cout<<i<<":";
			for(int j=head[i];j;j=edge[j].nex)
			{
				cout<<"("<<i<<","<<edge[j].to<<","<<edge[j].v<<")";
			}
			cout<<endl;
		}
	}
	return 0;
}
~~~



## **7-2**

同上题，可在输入数据时进行操作达到删点的目的

AC代码

~~~cpp
#include<bits/stdc++.h>

using namespace std;
int n,e,k;
struct node
{
	int to,nex,v,pre;
}edge[20005];
int head[20005];
int cnt;
void add(int a,int b,int c)
{
	edge[++cnt].to=b;
	edge[cnt].pre=a;
	edge[cnt].v=c;
	edge[cnt].nex=head[a];
	head[a]=cnt;
}
struct cmpp
{
	int a,b,c;
	int de;
}x[20005];
bool cmp(cmpp a,cmpp b)
{
	if(a.a<b.a)return true;
	else if(a.a>b.a)return false;
	else if(a.a==b.a)
	{
		if(a.b>b.b)return true;
		else return false;
	}
}
map<pair<int,int>,int>q;
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>x[i].a>>x[i].b>>x[i].c;
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		q[{a,b}]=1;
	}
	sort(x+1,x+1+e,cmp);
	for(int i=1;i<=e;i++)
	{
		if(!q[{x[i].a,x[i].b}])add(x[i].a,x[i].b,x[i].c);
	}
	for(int i=0;i<n;i++)
	{
		if(head[i]!=0)
		{
			cout<<i<<":";
			for(int j=head[i];j;j=edge[j].nex)
			{
				cout<<"("<<i<<","<<edge[j].to<<","<<edge[j].v<<")";
			}
			cout<<endl;
		}
	}
	return 0;
}
~~~



## **7-3**

图论里混了个dp，也可能是我太菜了，不会用图写

dp[i] [k]代表以num[i]结尾的，长度为k的子序列数量。

**基本递推**：

​        dp[i] [k]=dp[i] [k]+dp[j] [k-1];  (j<=i&&num[j]<=num[i])

​		最后的结果就是把所有的dp[i] [k]加起来

​		很好理解

**去重：**

1. 进行递推时，j倒序遍历

​		举个例子：

​				这个序列{1，2，5，3，5，7}

​				若正向遍历，则在计算dp[6] [3]时，会加上dp[3] [2]和dp[5] [2]，但是二者都包括{2，5}这样的序列，比		较二者发现，dp[3] [2]有的，dp[5] [2]都有，同时dp[5] [2]还有dp[3] [2]没有的，所以我们只用加上dp[5] [2]		即可，所以倒着遍历，并且标记num[j]是否使用过。

2. 计算最终结果时，也要倒序遍历

​			原因与第一条类似，dp[5] [2]和dp[3] [2]都包含{2，5}这样的序列，只用加一次即可

AC代码：

~~~cpp
#include<bits/stdc++.h>

using namespace std;
int n;
int ans;
int num[25];
int dp[25][25];//以num[i]结尾，长度为k的子序列数量 
map<int,int>q;//记录某个数是否用过
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		dp[i][1]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=i;k++)
		{
			q.clear();
			for(int j=i-1;j>=1;j--)//倒叙1.
			{
				if(num[j]<=num[i])
				{
					if(!q[num[j]])
					{
						q[num[j]]=1;
						dp[i][k]=dp[i][k]+dp[j][k-1];
					}
				}
			}
		}
	}
	q.clear();
	for(int i=n;i>=1;i--)//倒叙2.
	{
		if(!q[num[i]])
		{
			q[num[i]]=1;
			for(int j=2;j<=n;j++)
			{
				ans+=dp[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
~~~



## **7-4**

图论里又混了个奇怪的搜索

这个题也是老生常谈了，连通块

AC代码

~~~cpp
#include<bits/stdc++.h>

using namespace std;
int n,m;
int ma[105][105];
int ans;
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};
void dfs(int x,int y)
{
	ma[x][y]=0;
	for(int i=1;i<=4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			if(ma[xx][yy]==1)dfs(xx,yy);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ma[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ma[i][j]==1)
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
~~~



## **7-5**

仔细审题，理解是求最小生成树

结合题目输入方式，可使用Kruskal算法，用链式前向星存图

~~~cpp
#include<bits/stdc++.h>

using namespace std;
int n,m;
int s,maxn;
int sum;
struct node
{
	int pre,to,val;
}e[200005];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
int fa[305];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].pre>>e[i].to>>e[i].val;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].pre);
		int y=find(e[i].to);
		if(x==y)continue;
		else
		{
			fa[y]=x;
			if(e[i].val>maxn)maxn=e[i].val;
			sum++;
		}
		if(sum==n-1)break;
	}
	cout<<n-1<<" "<<maxn;
	return 0;
}
~~~



## **7-6**

最小支撑树就是最小生成树

如果加不够n-1条边，则说明不存在最小生成树

~~~
#include<bits/stdc++.h>

using namespace std;
int n,m;
int s;
int sum;
struct node
{
	int pre,to,val;
}e[3005];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
int fa[1505];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	while(cin>>n>>m)
	{
		s=0;
		sum=0;
		memset(fa,0,sizeof(fa));
		for(int i=1;i<=m;i++)
		{
			cin>>e[i].pre>>e[i].to>>e[i].val;
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x=find(e[i].pre);
			int y=find(e[i].to);
			if(x==y)continue;
			else
			{
				fa[y]=x;
				s+=e[i].val;
				sum++;
			}
			if(sum==n-1)break;
		}
		if(sum==n-1)cout<<s<<endl;
		else cout<<"There is no minimum spanning tree."<<endl;
	}
	return 0;
}
~~~



## **7-7**

7-5的升级版，对v点进行特殊判断即可

**建树前**：

​	link数组表示某点是否**只与特殊点连接**   1表示只与v连接，-1表示还连接有其他点 ，在输入时数据进行判断即可

​	lone表示只与v连接的点的数量 

​	若总点数大于3并且lone>=2，则说明不存在改造方案（然而数据比较水，不存在总点数小于等于3，并且所有点都只连接v的数据）

**建树：**

​	若有只与v连接的点（一定只有一个，否则在建树前就结束了），将该点记为lonepoint，先把v和lonepoint加到生成树中，

​	numv表示在v上修的路的数量 ，如果numv>1,则不能再在v上修路，遇到时要直接跳过

​	其他的就是正常的最小生成树

**AC代码**

~~~cpp
#include<bits/stdc++.h>

using namespace std;
int n,v,m;
int s;
int sum;
int lone;
int lonepoint;//只与v连接的点的数量 
int numv;//表示在v上修的路的数量 
struct node
{
	int pre,to,val;
}e[200005];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
int fa[305];
int link[305];//表示某点是否只与特殊点连接   1表示只与v连接，-1表示有其他点 
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	while(cin>>n>>v>>m)
	{
		s=0;
		sum=0;
		lone=0;
		lonepoint=-1;
		numv=0;
		memset(fa,0,sizeof(fa));
		memset(link,0,sizeof(link));
		for(int i=1;i<=m;i++)
		{
			cin>>e[i].pre>>e[i].to>>e[i].val;
			
			if(e[i].pre==v&&link[e[i].to]!=-1)link[e[i].to]=1;
			else if(e[i].pre!=v)link[e[i].to]=-1;
			
			if(e[i].to==v&&link[e[i].pre]!=-1)link[e[i].pre]=1;
			else if(e[i].to!=v)link[e[i].pre]=-1;
			
		}
		for(int i=0;i<n;i++)
		{
			if(link[i]==1)
			{
				lone++;
				lonepoint=i;
			}
		}
		if(lone>=2)
		{
			cout<<-1<<endl;
			continue;
		}
		sort(e+1,e+1+m,cmp);
		for(int i=0;i<n;i++)fa[i]=i;
		if(lonepoint!=-1)
		{
			fa[lonepoint]=v;
			numv++;
			sum++;
			for(int i=1;i<=m;i++)
			{
				if(e[i].pre==v&&e[i].to==lonepoint||e[i].pre==lonepoint&&e[i].to==v)
				{
					s+=e[i].val;
					break;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(e[i].pre==v||e[i].to==v)
			{
				if(numv+1>2)continue;
			}
			int x=find(e[i].pre);
			int y=find(e[i].to);
			if(x==y)continue;
			else
			{
				if(e[i].pre==v||e[i].to==v)//和点v有关的路径 
				{
					if(numv+1>2)continue;
					else numv++;
				}
				fa[x]=y;
				s+=e[i].val;
				sum++;
			}
			if(sum==n-1)break;
		}
		if(sum==n-1)cout<<s<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
~~~



## **7-8**

拓扑排序

[拓扑排序入门](https://blog.csdn.net/qq_41713256/article/details/80805338?ops_request_misc=%7B%22request%5Fid%22%3A%22164056505716780261970810%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=164056505716780261970810&biz_id=0&spm=1018.2226.3001.4187)

每次从队列弹出节点时，它通向的节点的入度都减1，若某点入度为0，则加入队列

若某时刻数列含有两个及以上的入度为0的点，则说明有多种方案

若最后有的节点入度不为0，则说明存在环，不存在可行方案

**AC代码**

~~~cpp
#include<bits/stdc++.h>

using namespace std;
int n,m;
struct node
{
	int nex,to,pre;
}e[105];
int head[105];
int cnt;
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int in[105];
int inzero;
int main()
{
	while(cin>>n>>m)
	{
		int flag=0;
		int ans=0;
		cnt=0;
		memset(head,0,sizeof(head));
		memset(in,0,sizeof(in));
		for(int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			add(b,a);
			in[a]++;
		}
		queue<int>q;
		for(int i=1;i<=n;i++)
		{
			if(in[i]==0)q.push(i);
		}
		while(!q.empty())
		{
			if(q.size()>1)
			{
				flag=1;
			}
			int x=q.front();
			q.pop();
			for(int i=head[x];i;i=e[i].nex)
			{
				int y=e[i].to;
				in[y]--;
				if(in[y]==0)q.push(y);
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(in[i]!=0)ans=1;//有环 
		}
		if(ans==0)
		{
			if(flag==1)cout<<2<<endl;
			else cout<<1<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
~~~