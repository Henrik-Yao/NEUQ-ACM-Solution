#include<bits/stdc++.h>
using namespace std;
const int M=0x7ffffff;
int dis[105][105];
int main()
{
	int n,e;
	while(cin>>n>>e)
	{
		int _min=M,t;
		memset(dis,0x3f,sizeof(dis));
		int x,y,d;
		while(e--)
		{
			cin>>x>>y>>d;
			dis[x][y]=d;
			dis[y][x]=d;
		}
		for(int i=0;i<n;i++)
		dis[i][i]=0;
		for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if(dis[i][j]>dis[i][k]+dis[k][j])
		dis[i][j]=dis[i][k]+dis[k][j];
		for(int i=n-1;i>=0;i--)
		{
			int sum=0;
			for(int j=0;j<n;j++)
			sum+=dis[i][j];
			if(sum<=_min)
			{
				t=i;
				_min=sum;
			}
		}
		cout<<t<<endl;
	}
}
