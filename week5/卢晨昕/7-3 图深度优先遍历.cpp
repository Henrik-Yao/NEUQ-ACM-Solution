#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,e;
struct edgg
{
	int a,b;
}edg[55];
struct node
{
	int nex,fo,to;
}ed[40005];
int head[40005];
int cnt;
int v[40005];
void add(int a,int b)
{
	ed[++cnt].fo=a;
	ed[cnt].to=b;
	ed[cnt].nex=head[a];
	head[a]=cnt;
}
void dfs(int now)
{
	for(int i=head[now];i;i=ed[i].nex)
	{
		int y=ed[i].to;
		if(v[y]==0)
		{
			v[y]=1;
			cout<<y<<" ";
			dfs(y);
		}
	}
}
bool cmp(edgg a,edgg b)
{
	if(a.a>b.a)return true;
	else if(a.a<b.a)return false;
	else if(a.a==b.a)
	{
		return a.b>b.b;
	}
}
bool check()
{
	for(int i=0;i<n;i++)
	{
		if(v[i]==0)return false;
	}
	return true;
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>edg[i].a>>edg[i].b;
	}
	sort(edg+1,edg+1+e,cmp);
	for(int i=1;i<=e;i++)
	{
		add(edg[i].a,edg[i].b);
	}
	cout<<"0 ";
	v[0]=1;
	dfs(0);
	while(1)
	{
		if(check())return 0;
		else
		{
			for(int i=0;i<n;i++)
			{
				if(v[i]==0)
				{
					cout<<i<<" ";
					v[i]=1;
					dfs(i);
				}
			}
		}
	}
	return 0;
}
