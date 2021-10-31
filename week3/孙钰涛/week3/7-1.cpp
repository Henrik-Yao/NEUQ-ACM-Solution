#include<iostream>
using namespace std;
int m,n,k,city[101],road[101][101],flag=0;

void dfs(int begin,int end)
{
	if(begin==end)
	{
		flag=1;
		return ;
	}
	for(int i=0;i<=m;i++)
	{
			if(road[begin][i]==1 && city[i]==0)
			{
				city[i]=1;
				dfs(i,end);
				city[i]=0;
			}
	}
	return ;
}

int main()
{
	cin>>m>>n>>k;
	for(int i=0;i<=100;i++) city[i]=1;
	for(int i=1;i<=n;i++)
	{
		int o;
		cin>>o;
		city[o]=0;
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		road[x][y]=1;
		road[y][x]=1;
	} 
	int begin,end;
	cin>>begin>>end;
	city[begin]=1;
	if(city[end]==1) cout<<"The city "<<end<<" is not safe!";
	else
	{
		dfs(begin,end);
		if(flag==1) cout<<"The city "<<end<<" can arrive safely!";
		else cout<<"The city "<<end<<" can not arrive safely!";
	}
    return 0;
}