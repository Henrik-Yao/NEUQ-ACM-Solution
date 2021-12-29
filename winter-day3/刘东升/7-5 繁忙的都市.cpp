#include<bits/stdc++.h>
using namespace std;
int F[10005];
struct Edge
{
	int from;
	int to;
	int w;
}edge[10005];
bool cmp(Edge x,Edge y);
int find(int x);
bool fun(int a,int b);
int main()
{
	int n,e,i;
	cin>>n>>e;
		int max=0,cnt=0;
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
				max=edge[i].w;
				cnt++;
			}
			if(cnt==n-1)
			break;
		}
		cout<<cnt<<' '<<max;
}
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(F[x]==x)
	return F[x];
	else
	return F[x]=find(F[x]);
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
