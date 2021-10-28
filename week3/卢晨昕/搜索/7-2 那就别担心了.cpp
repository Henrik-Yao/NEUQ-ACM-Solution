#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n,m;
int be,en;
int ans;
int flag;
int ma[505];
struct node
{
	int to,nex;
}e[200005];
int head[200005],cnt=0;
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int num[505];
int dfs(int now)
{
	if(num[now]!=0)
	{
		return num[now];
	}
	for(int i=head[now];i;i=e[i].nex)
	{
		int y=e[i].to;
		if(ma[y]==0)
		{
			ma[y]=1;
			dfs(y);
			ma[y]=0;
		}
		num[now]+=num[y];
	}
	if(num[now]==0)
	{
		flag=1;
	}
	return num[now];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	cin>>be>>en;
	ma[be]=1;
	num[en]=1;
	cout<<dfs(be);
	if(flag==1)cout<<" No";
	else cout<<" Yes";
	return 0;
}
