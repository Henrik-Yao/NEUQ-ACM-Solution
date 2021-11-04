#include<bits/stdc++.h>
using namespace std;
bool mmap[1002][1002];
int n,m,x,y,cnt,a,b,t,d[4][2]={{0,1},{0,-1},{1,0},{-1,0}},vis[1002][1002],belong[1002][1002],size[10000000];
//belong用于上色，size用于记录个数；
//cnt指不同类的颜色（联通块）
int dfs(int x,int y,int flag)
{
	int ans=1;
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+d[i][0],yy=y+d[i][1];
		if(xx<1||xx>n||yy<1||yy>n||mmap[xx][yy]==flag)
		continue;
		if(!vis[xx][yy])
		{
			belong[xx][yy]=cnt;
			ans+=dfs(xx,yy,!flag);
		}
	}
	return ans;
}
int main()
{
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>ch;
			if(ch=='0')
			{
				mmap[i][j]=0;
			}
			else 
			{
				mmap[i][j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(!vis[x][y])
		{
			cnt++;
			belong[x][y]=cnt;
			size[cnt]=dfs(x,y,mmap[x][y]);
			printf("%d\n",size[cnt]);
		}
		else 
		{
			printf("%d\n",size[belong[x][y]]);
		}
		
	}
	return 0;
}