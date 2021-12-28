#include <bits/stdc++.h>
using namespace std;
int n,m,fa[100001],ans=-1;
struct edge
{
	int s,e,v;
}mp[200001];
bool cmp(edge x,edge y)
{
	return x.v<y.v;
}
int find(int x)
{
	if(x==fa[x])
	return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=fa[y];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>mp[i].s>>mp[i].e>>mp[i].v;
	}
	sort(mp+1,mp+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(mp[i].s)==find(mp[i].e))
		{
			continue;
		}
		ans=max(ans,mp[i].v);
		merge(mp[i].s,mp[i].e);
	}
	cout<<n-1<<" "<<ans;
	return 0;
}
