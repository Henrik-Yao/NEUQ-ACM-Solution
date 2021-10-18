#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
int a[maxn],q[maxn],h[maxn],vis[100005];
int maxx=-111111;
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!vis[a[i]])
		{
			q[i]=q[i-1]+1;
			vis[a[i]]++;
		}
		else q[i]=q[i-1];
	}
	memset(vis,0,sizeof(vis));
	for(int i=n;i>0;i--)
	{
		if(!vis[a[i]])
		{
			h[i]=h[i+1]+1;
			vis[a[i]]++;
		}
		else h[i]=h[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,q[i]+h[i+1]);
	}
	cout<<maxx;
	return 0;
}

