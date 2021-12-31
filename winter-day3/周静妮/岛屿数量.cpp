#include <bits/stdc++.h>
using namespace std;

const int maxn=1234;
int dr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
int space[maxn][maxn];

void dfs(int x,int y)
{		
	space[x][y]=2;
	for(int i=0;i<4;i++)
	{
		int nowx=x+dr[i][0];
		int nowy=y+dr[i][1];
		if(nowx<0||nowy<0||nowx>n||nowy>m)	continue;	
		if(space[nowx][nowy]==1)	dfs(nowx,nowy);		
	}
}

int main()
{
	int i,j,sum=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		cin>>space[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(space[i][j]==1)	
			{
				dfs(i,j);
				sum++;
			}
		}
	cout<<sum;
	return 0;
 } 
