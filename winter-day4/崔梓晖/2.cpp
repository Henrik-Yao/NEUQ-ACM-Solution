#include <bits/stdc++.h>
using namespace std;
int n,m,a[100][100],dis[100],vis[100],s,k,e,st,en;
void dijie(int st,int en)
{
	int u;
	for(int i=0;i<n;i++)
	{
		dis[i]=a[st][i];
	}
	vis[st]=1;
	int minn;
	for(int i=0;i<n;i++)
	{
		minn=1000000;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==0&&dis[j]<=minn)
			{
				minn=dis[j];
				u=j;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(dis[j]>=dis[u]+a[u][j])
			{
				dis[j]=dis[u]+a[u][j];
			}
		}
	}
	if(dis[en]>=10000)
	{
		cout<<"connection impossible"<<endl;
	}
	else
	cout<<dis[en]<<endl;
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i==j)
				{
					a[i][j]=0;
					a[j][i]=0;
				}
				else 
				{
					a[i][j]=10000;
					a[j][i]=10000;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>s>>k;
			for(int i=1;i<=k;i++)
			{
				cin>>e;
				a[s][e]=1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cin>>st>>en;
			memset(vis,0,sizeof(vis));
			memset(dis,0,sizeof(dis));
			dijie(st,en);
		}
	}
	return 0;
}

