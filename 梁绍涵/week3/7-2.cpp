#include<bits/stdc++.h>
using namespace std;
int n,m,ma[600][600],vis[600],flag=1,a[600];
int u,v,ans=0;
int dfs(int k)
{
	if(a[k]) return a[k];
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(ma[k][i]==0) continue;
		if(a[i]);
		else 
		dfs(i);
		res+=a[i];
	}
	if(res==0)
	flag=0;
	return a[k]=res;
}
int main()
{
	cin>>n>>m;
	memset(ma,0,sizeof(ma));
	for(int i=1;i<=m;i++)
	{
		int ui,vi;
		cin>>ui>>vi;
		ma[ui][vi]=1;
	}
	cin>>u>>v;
	a[v]=1;
	ans=dfs(u);
	cout<<ans;
	if(flag==0) cout<<" No";
	else cout<<" Yes";
}
