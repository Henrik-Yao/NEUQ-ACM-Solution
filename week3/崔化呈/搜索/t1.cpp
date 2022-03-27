#include<bits/stdc++.h>
using namespace std;
int dao=0;
int begincity,endcity;
int m,n,k;
int city[110],visit[110],road[110][110];
void dfs(int now)
{
	if(dao==1){return;}
	if(now==endcity)
	{
		dao=1;
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(city[i]==1&&visit[i]==0&&road[now][i]==1)
		{
			visit[i]=1;
			dfs(i);
			visit[i]=0;
		}
	}
}
int main()
{
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int sc;
		cin>>sc;
		city[sc]=1;
	}
	for(int i=1;i<=k;i++)
	{
		int s,e;
		cin>>s>>e;
		road[s][e]=1;
		road[e][s]=1;
	}
	
   scanf("%d %d",&begincity,&endcity);
	if(city[endcity]==0){cout<<"The city "<<endcity<<" is not safe!";return 0;}
	else{}
	visit[begincity]=1;
	dfs(begincity);
	if(dao==1)
	{
		cout<<"The city "<<endcity<<" can arrive safely!";
		return 0;
	}
	else
	{
	cout<<"The city "<<endcity<<" can not arrive safely!";
		return 0;
	}
	}
	
