#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<set>
#include<cmath> 
#define int long long
#define maxn 1000005
using namespace std;
int ll=1e16;

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

struct node{
	int c,val;
};
struct edge{
	int next,to;
	double dis;
}g1[maxn],g2[maxn];
int n,m,qq,aa,bb,cc,dd,num1,num2,last1[maxn],last2[maxn];
int vis1[maxn],vis2[maxn],d1[maxn],d2[maxn],f[maxn];
multiset<int>s;
priority_queue<node>q;
bool operator<(node a,node b){return a.val>b.val;}

void add1(int from,int to,int dis)
{
	g1[++num1].next=last1[from];
	g1[num1].to=to;
	g1[num1].dis=dis;
	last1[from]=num1;
}

void add2(int from,int to,int dis)
{
	g2[++num2].next=last2[from];
	g2[num2].to=to;
	g2[num2].dis=dis;
	last2[from]=num2;
}

void dj1()
{
	for(int i=1;i<=n;i++) d1[i]=ll;
	q.push((node){1,0});d1[1]=0;
	while(q.size())
	{
		node u=q.top();q.pop();
		if(vis1[u.c]) continue;
		vis1[u.c]=1;
		for(int i=last1[u.c];i;i=g1[i].next)
		{
			int v=g1[i].to;
			if(d1[v]>d1[u.c]+g1[i].dis)
			{
				d1[v]=d1[u.c]+g1[i].dis;
				q.push((node){v,d1[v]});
			}
		}
	}
}
void dj2()
{
	for(int i=1;i<=n;i++) d2[i]=ll;
	q.push((node){n,0});d2[n]=0;
	while(q.size())
	{
		node u=q.top();q.pop();
		if(vis2[u.c]) continue;
		vis2[u.c]=1;
		for(int i=last2[u.c];i;i=g2[i].next)
		{
			int v=g2[i].to;
			if(d2[v]>d2[u.c]+g2[i].dis)
			{
				d2[v]=d2[u.c]+g2[i].dis;
				q.push((node){v,d2[v]});
			}
		}
	}
}

signed main()
{
	n=read();m=read();qq=read();
	for(int i=1;i<=m;i++)
	{
		aa=read();bb=read();cc=read();dd=read();
		add1(aa,bb,cc);
		add2(bb,aa,dd);
	}
	dj1();dj2();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		if(vis1[i]==0||vis2[i]==0) continue;
		s.insert(d1[i]+(d2[i]+aa-1)/aa);
		f[i]=d1[i]+(d2[i]+aa-1)/aa;
	}
	for(int i=1;i<=qq;i++)
	{
		aa=read();bb=read();
		if(vis1[aa]==0||vis2[aa]==0)
		{
			printf("%lld\n",*s.begin());
			continue;
		}
		multiset<int>::iterator it;
		it=s.find(f[aa]);
		s.erase(it);
		f[aa]=d1[aa]+(d2[aa]+bb-1)/bb;
		s.insert(f[aa]);
		printf("%lld\n",*s.begin());
	}
	return 0;
}
