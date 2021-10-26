# 7-1 生化危机 

标记一下不安全的城市，dfs便利即可

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1005
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

struct edge
{
	int next,to;
}g[maxn<<1];

int n,m,k,aa,bb,num,s,t;
int last[maxn],vis[maxn];

void add(int from,int to)
{
	g[++num].next=last[from];
	g[num].to=to;
	last[from]=num;
}

void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		dfs(v);
	}
}

int main()
{
	n=read();k=read();m=read();
	for(int i=1;i<=n;i++)
	vis[i]=1;
	for(int i=1;i<=k;i++)
	{
		aa=read();vis[aa+1]=0;
	}
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		aa++;bb++;
		add(aa,bb);
		add(bb,aa);
	}
	s=read();t=read();
	s++;t++;
	vis[s]=0;
	if(vis[t])
	{
		printf("The city %d is not safe!\n",t-1);
		return 0;
	}
	dfs(s);
	if(vis[t]) printf("The city %d can arrive safely!\n",t-1);
	else printf("The city %d can not arrive safely!\n",t-1);
	return 0;
}
~~~

# 7-2 那就别担心了 

有向无环图，经典拓扑+dp，那么如何判断逻辑自洽呢，只需要判断是否存在点使其满足下述条件
$$
1_. 从起点出发可达 \\   
2_. 不可以抵达终点
$$
只需在拓扑排序时不走终点发出的边，然后判断是否存在出度为零的点且此点从起点有路径抵达。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

struct edge
{
	int next,to;
}g[maxn<<1];
queue<int>q;
int n,m,num,pd,aa,bb,s,t;
int last[maxn],de[maxn],f[maxn],d[maxn];

void add(int from,int to)
{
	g[++num].next=last[from];
	g[num].to=to;
	last[from]=num;
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		add(aa,bb);
		de[bb]++;
		d[aa]++;
	}
	s=read();t=read();
	f[s]=1;
	for(int i=1;i<=n;i++)
	{
		if(de[i]==0)
		q.push(i);
	}
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=last[u];i;i=g[i].next)
		{
			int v=g[i].to;
			f[v]=f[v]+f[u];
			if(v!=t) de[v]--;
			if(de[v]==0) q.push(v);
		}
	}
	cout<<f[t]<<" ";
	for(int i=1;i<=n;i++)
	{
		if(f[i]&&d[i]==0&&i!=t)
		pd=1;
	}
	if(pd==0) puts("Yes");
	else puts("No");
	return 0;
}
~~~

# 7-3 扫雷游戏 

搜素+模拟，细节注意好即可

```
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int n,m,k,l,num,aa,bb;
int a[30][30],f[30][30],vis[30][30],aaa[9]={0,1,1,1,0,0,-1,-1,-1},b[9]={0,-1,0,1,1,-1,-1,0,1};

void dfs(int x,int y)
{
	num++;
	vis[x][y]=f[x][y];
	if(vis[x][y]) return;
	for(int i=1;i<=8;i++)
	{
		int xx=x+aaa[i];
		int yy=y+b[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]==-1)
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	n=read();m=read();k=read();l=read();
	for(int i=1;i<=k;i++)
	{
		aa=read();bb=read();
		aa++;bb++;
		a[aa][bb]=1;
		f[aa+1][bb+1]++;f[aa+1][bb]++;f[aa+1][bb-1]++;
		f[aa][bb-1]++;f[aa][bb+1]++;
		f[aa-1][bb+1]++;f[aa-1][bb]++;f[aa-1][bb-1]++;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		vis[i][j]=-1;
	}
	for(int i=1;i<=l;i++)
	{
		aa=read();bb=read();
		aa++;bb++;
		if(a[aa][bb])
		{
			puts("You lose");
			return 0;
		}
		if(vis[aa][bb]!=-1) continue;
		if(f[aa][bb])
		{
			num++;
			vis[aa][bb]=f[aa][bb];
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				printf("%d ",vis[i][j]);
				puts("");
			}
			
		}
		else if(f[aa][bb]==0)
		{
			dfs(aa,bb);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				printf("%d ",vis[i][j]);
				puts("");
			}
		}
		if(num==n*m-k)
		{
			puts("You win");
			return 0;
		}
		puts("");
	}
	return 0;
}
```



# 7-4 01迷宫 

搜索出每个点所属的连通块和每个连通块的大小，对于每次询问O（1）回答即可

~~~c++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#define maxn 1005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int a[5]={0,1,0,-1,0},b[5]={0,0,1,0,-1},aa,bb;
int n,m,vis[maxn][maxn],tot,sum,ans[1000005],co[maxn][maxn];
char c[maxn][maxn];

void dfs(int x,int y)
{
	if(vis[x][y]) return;
	sum++;
	vis[x][y]=1;co[x][y]=tot;
	for(int i=1;i<=4;i++)
	{
		int xx=x+a[i];
		int yy=y+b[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&c[xx][yy]!=c[x][y])
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	cin>>(c[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
			{
				tot++;sum=0;
				dfs(i,j);
				ans[tot]=sum;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		printf("%d\n",ans[co[aa][bb]]);
	}
	return 0;
}
~~~

