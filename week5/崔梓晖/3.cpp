#include <bits/stdc++.h>
using namespace std;
vector<int>v[200001];
int n,e,vis[200001],a,b;
void dfs(int now)
{
	cout<<now<<" ";
	vis[now]=1;
	for(int i=0;i<v[now].size();i++)
	{
		if(vis[v[now][i]]==0)
		dfs(v[now][i]);
	}
}
int main()
{
	cin>>n>>e;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=e;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
	}
	for(int i=0;i<n;i++)
	{
		sort(v[i].begin(),v[i].end());
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		dfs(i);
		else continue;
	}
	return 0;
}
