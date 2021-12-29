#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,e;
	while(cin>>n)
	{
		cin>>e;
	int map[n+1][n+1];
	int dis[n+1];
	bool jud[n+1];
	for(int i=1;i<=n;i++) 
	{
		jud[i]=0;
		for(int j=1;j<=n;j++) map[i][j] =99999;
	}
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		map[a][b] = c;
		map[b][a] = c;
	}
	for(int i=1;i<=n;i++) dis[i]=map[1][i];
	jud[1]=1;
	int sum=0;
	bool judge = 0;
	for(int k=1;k<n;k++)
	{
		int min =99999;
		int minindex;
		for(int i=1;i<=n;i++)
		if(dis[i]<min&&!jud[i]) 
		{
			min = dis[i];
			minindex = i;
		}
		if(min == 99999)
		{
			judge = 1;
			cout<<"There is no minimum spanning tree."<<'\n';
			break;
		}
		jud[minindex]=1;
		sum+=min;
		for(int i=1;i<=n;i++)
		{
			if(!jud[i]&&map[minindex][i]<dis[i]) dis[i]=map[minindex][i];
		}
	}
	if(!judge) cout<<sum<<'\n';
	 } 
	return 0;
} 
