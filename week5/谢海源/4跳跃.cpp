#include<bits/stdc++.h>
using namespace std;
int m[1000001]={};
bool v[1000001]={};
int n,sta,f=0;
void dfs(int x)
{
	if(f==1||v[x]==1) return;
	v[x]=1;
	if(m[x]==0)
	{
		f=1;
		return;
	}
	if(x+m[x]<n&&x+m[x]>=0&&v[x+m[x]]==0) dfs(x+m[x]);
	if(x-m[x]<n&&x-m[x]>=0&&v[x-m[x]]==0) dfs(x-m[x]);
}
int main()
{
	memset(m,0,sizeof(m));
	memset(v,0,sizeof(v));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
	}
	cin>>sta;
	dfs(sta);
	if(f==0) cout<<"False";
	else cout<<"True";
	return 0;
}