#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	x=x*10+(ch^48),ch=getchar();
	return x*f;
} 
int n,e,vis[20005];
struct ax
{
	int to[51];
	int tot;
	void sp()
	{
		sort(to+1,to+tot+1);
	}
}a[20005];
void dfs(int x)
{
	if(vis[x]==0)a[x].sp();
	vis[x]=1;
	cout<<x<<" ";
	if(a[x].tot==0)return;
	for(int i=1;i<=a[x].tot;i++)
	{
		int ap=a[x].to[i];
		if(!vis[ap])
		dfs(ap);
	}
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		int x,y;
		x=read(),y=read();
		a[x].to[++a[x].tot]=y;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])dfs(i);
	}
	return 0;
}
