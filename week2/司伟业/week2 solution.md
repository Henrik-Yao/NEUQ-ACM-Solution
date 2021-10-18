# 7-1 汉诺塔问题

考虑（n=1）时的情况，只需要移动一下， (n>1)时我们需要把n-1个塔移动到一个柱子上，再把第n个移动到另一个柱子上，最后再将n-1个塔移到第n个塔上，因此可以将1~n分解为1~n-1和n两个子结构，设mid=6-from-to,则有：
$$
f(num,from,to)=
\left\{
\begin{aligned}
f&(num-1,from,mid)\\
f&(1,from,to)\\
f&(num-1,mid,to)
\end{aligned}
\right.
$$
然后递归求解即可，递归边界（n==1）

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100
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

int n;
char aa[maxn][maxn];

void f(int num,int from,int to)
{
    int mid=6-from-to;
	if(num==1)
	{
		printf("%s->%s\n",aa[from],aa[to]);
		return;
	}
	f(num-1,from,mid);
	f(1,from,to);
	f(num-1,mid,to);
}

int main()
{
	n=read();
	for(int i=1;i<=3;i++) scanf("%s",aa[i]);
	f(n,1,3);
	return 0;
}

~~~



#  7-2 分而治之

对于每次询问判断图中是否有大小大于1的连通块即可

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

struct edge
{
	int next,to;
}g[maxn<<1];

int n,m,k,aa,bb,num,p,ans;
int last[maxn],vis[maxn];

void dfs(int x)
{
	for(int i=last[x];i;i=g[i].next)
	{
		int v=g[i].to;
		if(!vis[v]) ans=2;
	}
}

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
		add(bb,aa);
	}
	k=read();
	while(k--)
	{
		p=read();
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=p;i++)
		{
			aa=read();
			vis[aa]=1;
		}
		int pd=0;
		for(int i=1;i<=n;i++)
		{
			ans=0;
			if(!vis[i])
			dfs(i);
			if(ans>1) pd=1;
		}
		if(pd==1) puts("NO");
		else puts("YES");
	}
}

~~~

# 7-3 归并排序

每次将序列一分为二，然后开两个指针分别指向前一半和后一半，由于每次排序时前一半和后一半序列分别有序，只需要从前往后扫一遍即可。

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

int n,a[maxn],b[maxn];

void guibing(int l,int r)
{
	if(r==l) return;
	int mid=(l+r)/2;
	guibing(l,mid);guibing(mid+1,r);
	int l1=l,l2=mid+1;
	for(int i=l;i<=r;i++)
	{
		if(l1>mid)
		{
			b[i]=a[l2];l2++;
		}
		else if(l2>r)
		{
			b[i]=a[l1];l1++;
		}
		else if(a[l1]<a[l2])
		{
			b[i]=a[l1];l1++;
		}
		else if(a[l1]>=a[l2])
		{
			b[i]=a[l2];l2++;
		}
	}
	for(int i=l;i<=r;i++) a[i]=b[i];
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	guibing(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
~~~

