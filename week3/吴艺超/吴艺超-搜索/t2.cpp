#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int m,n,a,b,flag,vis[501];
vector<int> ax[501];
int dfs(int x)
{
	if(vis[x]!=0)return vis[x];
	for(int i=0;i<ax[x].size();i++)
	{
		int to=ax[x][i];
		if(vis[to]==0)dfs(to);
		vis[x]+=vis[to];
	}
	if(vis[x]==0)flag=1;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=read(),y=read();
		ax[x].push_back(y);
	}
	cin>>a>>b;
	vis[b]=1;
	dfs(a);
	cout<<vis[a];
	if(flag==1)cout<<" No";
	else cout<<" Yes";
	return 0;
}
