#include<iostream>
using namespace std;
int m,n,num=0,a[2001][2001],vis[2001][2001];
int xi[4]={-1,0,0,1},yi[4]={0,1,-1,0};
void island(int i,int j)
{
    int k;
    vis[i][j]=1;		
	for(k=0;k<4;k++)
	{
	    int x=i+xi[k],y=j+yi[k];
	    if(x<0||x>=m||y<0||y>=n||a[x][y]==0||vis[x][y]==1)
	    {
	    	continue;
		}
		island(x,y);
	}
}
int main()
{
	int i,j;
	cin>>m>>n;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
			vis[i][j]=0;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(vis[i][j]==1||a[i][j]==0)
			{
				continue;
			}
			island(i,j);
			num++;
		}
	}
	cout<<num;
	return 0;
}
