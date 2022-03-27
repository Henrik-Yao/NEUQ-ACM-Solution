# **7-1 愿天下有情人都是失散多年的兄妹**

对关系网建立由子女指向双亲的有向图，由题意得该有向图没有环，同时需要标记每个人的性别，包括双亲，因为查询中可能会出现双亲，对于每次询问只需要暴力向上查找四层即可，判断是否有四层以内的公共祖先。 

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 200005
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
int n,num,last[maxn],s[maxn],vis[maxn];
char a[10],f1[10],f2[10],sex;
int aa,bb,cc,q,pd;

void add(int from,int to)
{
	g[++num].next=last[from];
	g[num].to=to;
	last[from]=num;
}

void dfs(int x,int t)
{
	if(t==6) return;
	vis[x]=1;
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		dfs(v,t+1);
	}
}

void dfs1(int x,int t)
{
	if(pd) return;
	if(t==6) return;
	if(vis[x])
	{
		pd=1;
		return;
	}
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		dfs1(v,t+1);
	}
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>a>>sex>>f1>>f2;
		
		if(a[0]!='-') aa=(a[0]-'0')*10000+(a[1]-'0')*1000+(a[2]-'0')*100+(a[3]-'0')*10+(a[4]-'0');
		if(f1[0]!='-') bb=(f1[0]-'0')*10000+(f1[1]-'0')*1000+(f1[2]-'0')*100+(f1[3]-'0')*10+(f1[4]-'0');
		if(f2[0]!='-') cc=(f2[0]-'0')*10000+(f2[1]-'0')*1000+(f2[2]-'0')*100+(f2[3]-'0')*10+(f2[4]-'0');
		if(f1[0]!='-') add(aa,bb),s[bb]=0;
		if(f2[0]!='-') add(aa,cc),s[cc]=1;
		if(sex=='M') s[aa]=0;//0~~~?
		else s[aa]=1;//1~~~? 
//		cout<<aa<<" "<<bb<<" "<<cc<<endl; 
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		cin>>f1>>f2;pd=0;
		bb=(f1[0]-'0')*10000+(f1[1]-'0')*1000+(f1[2]-'0')*100+(f1[3]-'0')*10+(f1[4]-'0');
		cc=(f2[0]-'0')*10000+(f2[1]-'0')*1000+(f2[2]-'0')*100+(f2[3]-'0')*10+(f2[4]-'0');
		if(s[bb]==s[cc])
		{
			puts("Never Mind");
			continue;
		}
		memset(vis,0,sizeof(vis));
		dfs(bb,1);
		dfs1(cc,1);
		if(pd) 
		{
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
} 
~~~

# **7-2 哥德巴赫最新猜想**

首先一个判断这个数本身是否是素数，如果是答案就是1，由哥德巴赫猜想可知如果是偶数答案为2，然后对于奇合数只需判断其减去2是否为质数即可，因为奇合数减去任意一个非2的质数一定为偶数，一定可以分解为三个质数的和。
$$
ans=\begin{cases}
1 ，n为质数\\
2，n为偶数或(n{-}2)为质数 \\
3，为奇合数且(n{-}2)不为质数
\end{cases}
$$

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100005
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

int n,aa,pd,pd1;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();pd=0;pd1=0;
		for(int i=2;i*i<=aa;i++)
		{
			if(aa%i==0)
			pd=1;
		}
		for(int i=2;i*i<=aa-2;i++)
		{
			if((aa-2)%i==0)
			pd1=1;
		}
		if(pd==0){
			puts("1");continue;
		}
		if(pd==1&&aa%2==0)
		{
			puts("2");continue;
		}
		if(pd1==0)
		{
			puts("2");continue;
		}
		puts("3");
	}
	return 0;
}

~~~

# 7-3 图深度优先遍历

感觉题目描述非常不清楚，应该改为可从任意点为起点且可选择多个起点进行深度优先遍历，每次只需将出边对应节点排序然后从小到大走即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 20005
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
int n,m,aa,bb,num,last[maxn],vis[maxn];

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
	int a[maxn],tot=0;
	if(x==1) printf("0 ");
	else printf("%d ",x-1);
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		if(!vis[v])
		a[++tot]=v;
	}
	sort(a+1,a+1+tot);
	for(int i=1;i<=tot;i++)
	{
		dfs(a[i]);
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();
		aa++;bb++;
		add(aa,bb);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		dfs(i);
	}
	return 0;
}
~~~

# 7-4 山

山就是1的连通块，dfs求出连通块个数即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 2005
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

int n,m,a[maxn][maxn],vis[maxn][maxn],tot;
int xxx[5]={0,1,0,-1,0},yyy[5]={0,0,1,0,-1};

void dfs(int x,int y)
{
	vis[x][y]=tot;
	for(int i=1;i<=4;i++)
	{
		int xx=x+xxx[i],yy=y+yyy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&vis[xx][yy]==0&&a[xx][yy]==1)
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		a[i][j]=read();
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(vis[i][j]) continue;
		if(a[i][j]==1)
		{
			tot++;
			dfs(i,j);
		}
	}
	cout<<tot;
	return 0;
}

~~~

# 7-5 跳越

注意数组下标从0开始，dfs即可，注意将跳过的点打上标记。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 50005
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

int n,a[maxn],m,vis[maxn],pd;

void dfs(int x)
{
	if(pd==1) return;
	if(vis[x]) return;
	if(a[x]==0)
	{
		pd=1;return;
	}
	vis[x]=1;
	if(x+a[x]<n) dfs(x+a[x]);
	if(x-a[x]>=0) dfs(x-a[x]);
}

int main()
{
	n=read();
	for(int i=0;i<n;i++)
	{
		a[i]=read();
	}
	m=read();
	dfs(m);
	if(pd) printf("True");
	else printf("False");
	return 0;
}

~~~

