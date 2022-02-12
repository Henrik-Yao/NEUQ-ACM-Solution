#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Edge
{
	int from,to,val;
}edge[3000100];
bool vis[310];
int mp[310][310],fa[310],cur=1,ans;
int getf(int x)
{
	while(x!=fa[x])
	{
		x=fa[x]=fa[fa[x]];
	}
	return x;
}
void make(int x,int y)
{
	fa[x]=y;
}
void Kruskal()
{
	for(int i=1;i<=m;i++)
	{
		int nx=getf(edge[i].from);
		int ny=getf(edge[i].to);
//		cout<<edge[i].from<<" "<<edge[i].to<<endl; 
		if(nx==ny) continue;
		fa[ny]=nx;
		ans=edge[i].val;
		cur++;
		if(cur==n)
		break;
	}
	//cout<<cur;
	cout<<n-1<<" "<<ans;
}
bool cmp(Edge a,Edge b)
{
	return a.val<b.val;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[i].from=u;
		edge[i].to=v;
		edge[i].val=w;
	}
	sort(edge+1,edge+1+m,cmp);
	Kruskal();
}
