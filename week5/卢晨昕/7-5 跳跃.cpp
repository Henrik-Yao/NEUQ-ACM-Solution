#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int m;
int be;
bool ans=false;
int a[50005];
int v[50005];
void dfs(int now)
{
	if(ans==true)return;
	if(a[now]==0)
	{
		ans=true;
		return;
	}
	int s=a[now];
	if(now+s<=m)
	{
		if(v[now+s]==0)
		{
			v[now+s]=1;
	    	dfs(now+s);
	    	v[now+s]=0;
		}
	}
	if(now-s>=1)
	{
		if(v[now-s]==0)
		{
			v[now-s]=1;
		    dfs(now-s);
		    v[now-s]=0;
		}
	}
}
int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	cin>>be;
	be++;
	v[be]=1;
	dfs(be);
	if(ans==true)cout<<"True";
	else cout<<"False";
	return 0;
}
