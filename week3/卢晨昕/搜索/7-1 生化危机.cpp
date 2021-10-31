#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int m,n,k;
int s[105];
int guo[105];
int ma[105][105];
int be,en;
int ans=0;
void dfs(int now)
{
	if(ans==1)return;
	if(now==en)
	{
		ans=1;
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(i!=now&&s[i]==1&&ma[now][i]==1&&guo[i]==0)
		{
			guo[i]=1;
			dfs(i);
			guo[i]=0;
		}
	}
}
int main()
{
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int ss;
		cin>>ss;
		s[ss]=1;
	}
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		ma[a][b]=1;
		ma[b][a]=1;
	}
	cin>>be>>en;
	if(s[en]==0)
	{
		cout<<"The city "<<en<<" is not safe!";
		return 0;
	}
	guo[be]=1;
	dfs(be);
	if(ans==1)
	{
		cout<<"The city "<<en<<" can arrive safely!";
		return 0;
	}
	else
	{
		cout<<"The city "<<en<<" can not arrive safely!";
		return 0;
	}
	return 0;
}
