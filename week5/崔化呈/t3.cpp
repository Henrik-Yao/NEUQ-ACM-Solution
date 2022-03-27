#include<bits/stdc++.h>
using namespace std;
int vis[20010];
vector<int> v[20010];

void dfs(int now)
{
	cout<<now<<" ";
	vis[now]=1;
	int len=v[now].size();
	for(int i=0;i<len;i++)
	{
		if(vis[v[now][i]]==0)
		{
			dfs(v[now][i]);   
            
、		}
	}
}
int main()
{
	int n,e,a,b;
	cin>>n>>e;
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
		{
			dfs(i);
		}
	}
	return 0;
}
