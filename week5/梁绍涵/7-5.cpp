#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],flag=0;
bool vis[500005];
void dfs(int k)
{
	if(a[k]==0)
	{
		flag=1;
		return;
	}
	if(k+a[k]<n&&!vis[k+a[k]])
	{
		vis[k+a[k]]=1;
		dfs(k+a[k]);
		vis[k+a[k]]=0;
	}
	if(k-a[k]>=0&&!vis[k-a[k]])
	{
		vis[k+a[k]]=1;
		dfs(k-a[k]);
		vis[k+a[k]]=0;
	}
	return;
}
int main()
{
	cin>>n;	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	vis[m]=1;
	dfs(m);
	if(flag==1)
	cout<<"True";
	else
	cout<<"False";
}
