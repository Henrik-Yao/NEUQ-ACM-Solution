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
int n,m[50005],s,tot;
bool vis[50005];
void dfs(int x)
{
	if(m[x]==0)
	{
		tot=1;
		return;
	}
	if(x-m[x]>=0 && !vis[x-m[x]])
	{
		vis[x-m[x]]=1;
		dfs(x-m[x]);
//		vis[x-m[x]]=0;
	}
	if(x+m[x]<n && !vis[x+m[x]])
	{
		vis[x+m[x]]=1;
		dfs(x+m[x]);
//		vis[x-m[x]]=0;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		m[i]=read();
	s=read();
	vis[s]=1;
	dfs(s);
	if(tot==0)cout<<"False";
	else cout<<"True";
	return 0;
}
