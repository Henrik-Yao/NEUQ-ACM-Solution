#include<bits/stdc++.h>
using namespace std;
int n,e;
int vis[20005];
struct aaa
{
	int tot;
	int to[55];
	void px()
	{
		sort(to+1,to+tot+1);
	}
}a[20005];
void dfs(int x)
{
	if(!vis[x])
	{
		cout<<x<<" ";
		vis[x]=1;
		a[x].px();
		for(int i=1;i<=a[x].tot;i++)
		dfs(a[x].to[i]);
	}
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x].to[++a[x].tot]=y;
	}
	for(int i=0;i<n;i++)
	{
		dfs(i);
	}
}
