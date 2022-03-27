#include<bits/stdc++.h>
using namespace std;
const int M=50005;
struct edge
{
	int to,nex;
}e[M/2];
int head[M],tot=0;
void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].nex=head[x];
	head[x]=tot;
}
int dep[M],fa[M][22],lg[M];
void dfs(int now,int fath)
{
	fa[now][0]=fath;
	dep[now]=dep[fath]+1;
	for(int i=1;i<=lg[dep[now]];i++)
	{
		fa[now][i]=fa[fa[now][i-1]][i-1];
	}
	for(int i=head[now];i;i=e[i].nex)
	{
		if(e[i].to!=fath){dfs(e[i].to,now);}
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]){swap(x,y);}
	while(dep[x]>dep[y])
	{
		x=fa[x][lg[dep[x]-dep[y]]-1];
	}
	if(x==y){return x;}
	for(int i=lg[dep[x]]-1;i>=0;i--)
	{
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		stack<int> t;
		int tt,nu,r;
		cin>>tt;
		r=tt;
		t.push(tt);
		while(!t.empty())
		{
			cin>>tt;
			if(tt)
			{
				add(tt,t.top());
				add(t.top(),tt);
				t.push(tt);
				nu++;
			}
			else
			{
				t.pop();
			}
		}
		cin>>tt;
		for(int i=1;i<=nu;i++)
	{
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
		dfs(r,0);
		int x,y;
		cin>>x>>y;
		cout<<LCA(x,y)<<endl;
	}
	
	
	return 0;
}
