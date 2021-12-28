#include<bits/stdc++.h>
using namespace std;
int F[1501];
struct Edge
{
	int from;
	int to;
	int w;
}edge[1501];
bool cmp(Edge x,Edge y);
int find(int x);
bool fun(int a,int b);
int main()
{
	int n,e,i;
	while(~scanf("%d%d",&n,&e))
	{
		int total=0,cnt=0,flag=0;
		for(i=0;i<e;i++)
		{
			scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
		}
		for(i=0;i<n;i++)
			F[i]=i;
		sort(edge,edge+e,cmp);
		for(i=0;i<e;i++)
		{
			if(fun(edge[i].from,edge[i].to))
			{
				total+=edge[i].w;
				cnt++;
			}
			if(cnt==n-1)
			break;
		}
		if(cnt==n-1) printf("%d\n",total);
        else cout<<"There is no minimum spanning tree."<<endl;
	}
}
bool fun(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if(x!=y)
	{
		F[y]=x;
		return true;
	}
	return false;
}
int find(int x)
{
	if(F[x]==x)
	return F[x];
	else
	return F[x]=find(F[x]);
}
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
