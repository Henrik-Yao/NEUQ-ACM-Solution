#include <bits/stdc++.h>
using namespace std;
int n,p,e,fa[1001];
struct edge
{
	int s,e,v;
}mp[1001];
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=fa[y];
}
bool cmp(edge x,edge y)
{
	return x.v<y.v;
}
int main()
{
	while(cin>>n>>p>>e)
	{
		int in=0,tot=0,ans=0;
		for(int i=0;i<n;i++)
		{
			fa[i]=i;
		}
		for(int i=1;i<=e;i++)
		{
			cin>>mp[i].s>>mp[i].e>>mp[i].v; 
		}
		sort(mp+1,mp+e+1,cmp);
		for(int i=1;i<=e;i++)
		{
			if(find(mp[i].s)==find(mp[i].e)||((mp[i].s==p)||(mp[i].e==p))&&(in==2))
			{
				continue;
			}
			ans=ans+mp[i].v;
			if((mp[i].s==p)||(mp[i],e==p))
			{
				in++;
			}
			merge(mp[i].s,mp[i].e);
			tot++;
		}
		//cout<<"tot"<<tot<<endl;
		if(tot==n-1)
		{
			cout<<ans<<endl;
		}
		else cout<<"-1"<<endl;
	}
	return 0;
}
