#include<bits/stdc++.h>
using namespace std;
int w[1000][1000],con[1000][1000],temp[1000000][2],point[1000000][2];
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
int m,n,sx,sy,ex,ey,sum=0,cnt=0;
void DFS(int a,int b)
{
	if(a==ex&&b==ey)
	{
		for(int i=0;i<sum;i++)
		{
			point[i][0]=temp[i][0];
			point[i][1]=temp[i][1];
			cnt=sum;
		}
		return;
	}
	for(int i=0;i<4;i++)
	{
		int xx=a+x[i];
		int yy=b+y[i];
		if(xx<1||xx>m||yy<1||yy>n||w[xx][yy]==-1||con[xx][yy]<=con[a][b]+w[xx][yy])
		{
			continue;
		}
		temp[sum][0]=xx;
		temp[sum][1]=yy;
		con[xx][yy]=con[a][b]+w[xx][yy];
		sum++;
		DFS(xx,yy);
		sum--;
	}
}
int main()
{
	cin>>m>>n;
	cin>>sx>>sy>>ex>>ey;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>w[i][j];
			if(i>=1&&i<=m-2&&j>=1&&j<=n-2)
			{
				con[i][j]=65535;
			}
		}
	}
	con[sx][sy]=w[sx][sy];
	temp[sum][0]=sx;
	temp[sum][1]=sy;
	sum++;
	DFS(sx,sy);
	for(int i=cnt-1;i>=0;i--)
	{
		cout<<"("<<point[i][0]<<" "<<point[i][1]<<")";
	}
	return 0;
}
