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
