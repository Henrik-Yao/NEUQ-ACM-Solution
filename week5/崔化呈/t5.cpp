#include<bits/stdc++.h>
using namespace std;
int m[50005],vis[50005],n,sta;
bool flag;
void dfs(int now)
{
	if(m[now]==0)
	{
		flag=1;
		return;
	}
	if(flag)
	{
		return;
	}
	vis[now]=1;
	if(now+m[now]>=0&&now+m[now]<n&&vis[now+m[now]]==0)  //防越界
	{
		dfs(now+m[now]);
		vis[now+m[now]]=0;
	}
	if(now-m[now]>=0&&now-m[now]<n&&vis[now-m[now]]==0)
	{
		dfs(now-m[now]);
		vis[now-m[now]]=0;
	}
	
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m[i];
	}
	cin>>sta;
	dfs(sta);
	if(flag)
	{
		cout<<"True";
	}
	else
	{
		cout<<"False";
	}
	return 0;
}
