#include<bits/stdc++.h>
using namespace std;
const int M=500; 
int n,m,judge[M][M],vis[M],flag=1,a[M],u,v,answer=0;
int dfs(int u);
int main()
{
	cin>>n>>m;
	memset(judge,0,sizeof(judge));//清空一下 
	for(int i=1;i<=m;i++)//标记推论 
	{
		int u,v;
		cin>>u>>v;
		judge[u][v]=1;
	}
	cin>>u>>v;
	a[v]=1;//标记b 
	answer=dfs(u);
	cout<<answer;
	if(flag==0) 
	{
		cout<<" No";//用flag判断 
	} 
	else
	{
		cout<<" Yes";
	} 
}
int dfs(int u)
{
	if(a[u])//终点和起点重合时 
	{
		return a[u];
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(judge[u][i]==0)//未被标记则跳过 
		{
			continue; 
		} 
		if(a[i]);
		else 
		dfs(i);
		res+=a[i];
	}
	if(res==0)//如果没有则表示不能即no 
	flag=0;
	return a[u]=res;
}
