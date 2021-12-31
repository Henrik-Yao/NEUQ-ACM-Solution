#include <bits/stdc++.h>
using namespace std;
int n,a[500001],vis[500001],sx,flag=0;
void dfs(int x)
{
	vis[x]=1;
	if(a[x]==0)
	{
		flag=1;
		return;
	}
	if(vis[x-a[x]]==0&&x-a[x]>0)
	{
		dfs(x-a[x]);
	}
	if(vis[x+a[x]]==0&&x+a[x]<=n)
	{
		dfs(x+a[x]);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d", &a[i]);
	cin>>sx;
	dfs(sx+1);
	if(flag==1)
	{
		cout<<"True";
	}
	if(flag==0)
	{
		cout<<"False";
	}
	return 0;
}
