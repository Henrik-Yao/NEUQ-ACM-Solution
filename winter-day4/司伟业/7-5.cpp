#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#define int long long
#define maxn 1000005
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

struct node{int c,val;};
struct edge{
	int next,to,dis;
}g[maxn<<1];
int n,m,num,last[maxn],sx,sy,tx,ty;
int pre[maxn],vis[maxn],d[maxn],f[1005][1005];
int a1[5]={0,1,0,-1,0},a2[5]={0,0,1,0,-1};
priority_queue<node>q;
bool operator<(node a,node b)
{
	return a.val>b.val;
}

int get_xy(int x,int y)
{
	return x*m+y;
}

void add(int from,int to,int dis)
{
//	cout<<from<<" "<<to<<endl;
	g[++num].next=last[from];
	g[num].to=to;
	g[num].dis=dis;
	last[from]=num;
}

void dj()
{
	memset(d,0x3f,sizeof(d));
	q.push((node){get_xy(sx,sy),0});d[get_xy(sx,sy)]=0;
	while(q.size())
	{
		node u=q.top();q.pop();
		if(vis[u.c]) continue;
		vis[u.c]=1;
		for(int i=last[u.c];i;i=g[i].next)
		{
			int v=g[i].to;
			if(d[v]>d[u.c]+g[i].dis)
			{
				d[v]=d[u.c]+g[i].dis;
				q.push((node){v,d[v]});
				pre[v]=u.c;
			}
		}
	}
	int x=get_xy(tx,ty);
	while(1)
	{
		printf("(%d %d)",x/m,x%m);
		if(x==get_xy(sx,sy)) break;
		x=pre[x];
	}
}

signed main()
{
	m=read();n=read();
	sx=read();sy=read();tx=read();ty=read();
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	f[i][j]=read();
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(f[i][j]==-1) continue;
		for(int k=1;k<=4;k++)
		{
			int x=i+a1[k],y=j+a2[k];
			if(x>=0&&y>=0&&f[x][y]!=-1&&x<n&&y<m)
			{
				int aa=get_xy(x,y),bb=get_xy(i,j);
//				cout<<i<<" "<<j<<" "<<aa<<" "<<bb<<endl;
				add(bb,aa,f[x][y]);
				add(aa,bb,f[i][j]);
			}
		}
	}
	dj();
	return 0;
}
