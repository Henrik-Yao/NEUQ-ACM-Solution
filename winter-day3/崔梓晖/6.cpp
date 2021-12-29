#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int s,e,v;
}mp[3001];
int n,e,fa[3001];
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
bool cmp(edge x,edge y)
{
	return x.v<y.v;
}
int main()
{
	while(cin>>n>>e)
	{
	int cnt=0,ans=0,pd=0;
	for(int i=1;i<=n;i++)
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
		if(find(mp[i].s)==find(mp[i].e))
		{
			continue;
		}
		ans=ans+mp[i].v;
		merge(mp[i].s,mp[i].e);
		cnt++;
		if(cnt==n-1)
		{pd=1;
		 break;
	    }
	}
	if(pd==0)
	{
		cout<<"There is no minimum spanning tree."<<endl;
	}
	else 
	cout<<ans<<endl;
    }
	return 0;
}
