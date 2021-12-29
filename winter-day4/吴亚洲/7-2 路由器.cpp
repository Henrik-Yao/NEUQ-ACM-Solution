#include<bits/stdc++.h>
using namespace std;
const int M=0x7ffffff;
int dis[205][205];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			dis[i][j]=M;
			dis[j][i]=M;
		}
		int x,y,num;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>num;
			while(num--)
			{
				cin>>y;
				dis[x][y]=1;
			}
		}
		for(int i=0;i<n;i++)
		dis[i][i]=0;
		for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(dis[i][j]>dis[i][k]+dis[k][j])
		dis[i][j]=dis[i][k]+dis[k][j];
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			if(dis[a][b]>=n)
			cout<<"connection impossible"<<endl;
			else
			cout<<dis[a][b]<<endl;
		}
	}
}
