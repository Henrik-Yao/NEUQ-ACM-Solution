#include<bits/stdc++.h>

using namespace std;
int n,m;
int s,maxn;
int sum;
struct node
{
	int pre,to,val;
}e[200005];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
int fa[305];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].pre>>e[i].to>>e[i].val;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=find(e[i].pre);
		int y=find(e[i].to);
		if(x==y)continue;
		else
		{
			fa[y]=x;
			if(e[i].val>maxn)maxn=e[i].val;
			sum++;
		}
		if(sum==n-1)break;
	}
	cout<<n-1<<" "<<maxn;
	return 0;
}
