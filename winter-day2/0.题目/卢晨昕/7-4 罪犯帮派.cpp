//Á¬Í¨¿é 
#include<bits/stdc++.h>

using namespace std;
int n,m,q;
struct node
{
	int nex,fro,to;
}e[2005];
int head[2005];
int cnt;
void add(int a,int b)
{
	e[++cnt].fro=a;
	e[cnt].to=b;
	e[cnt].nex=head[a];
	head[a]=cnt;
}


int ans;
int v[1005];
void dfs(int x)
{
	v[x]=ans;
	for(int i=head[x];i;i=e[i].nex)
	{
		int y=e[i].to;
		if(!v[y])dfs(y);
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			ans++;
			dfs(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin>>a>>b;
		if(v[a]==v[b])cout<<"In the same gang."<<endl;
		else cout<<"In different gangs."<<endl;
	}
	cout<<ans;
	return 0;
}
