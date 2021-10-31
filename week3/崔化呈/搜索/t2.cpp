#include<bits/stdc++.h>
using namespace std;
int n,m,beginplace,endplace,flag;
int visit[550],ways[550];

struct node
{
	int to,nex;
}nd[300000];

int head[300000];
int linkn=1;
void link(int a,int b)
{
	nd[linkn].to=b;
	nd[linkn].nex=head[a];
	head[a]=linkn++;
}

int dfs(int now)
{
	if(ways[now]!=0)
	{
		return ways[now];
	}
	for(int i=head[now];i;i=nd[i].nex)
	{
		int y=nd[i].to;
		if(visit[y]==0)
		{
			visit[y]=1;
			dfs(y);
			visit[y]=0;
		}
		ways[now]+=ways[y];
	}
	if(ways[now]==0)
	{
		flag=1;
	}
	return ways[now];
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		link(a,b);
	}
	cin>>beginplace>>endplace;
	visit[beginplace]=1;
	ways[endplace]=1;
	cout<<dfs(beginplace);
	if(flag){cout<<" No"<<endl;}
	else{cout<<" Yes"<<endl;}
	return 0;
	
}
