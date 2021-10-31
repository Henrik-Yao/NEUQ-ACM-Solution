#include<bits/stdc++.h> 
using namespace std;
int a[21][21],b[21][21];
int dr[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int n,m,k,l;

int nb(int x,int y)
{
	int num=0;
	for(int i=0;i<8;i++)
	{
		int nowx=x+dr[i][0];
		int nowy=y+dr[i][1];
		if(nowx<0||nowy<0||nowx>n||nowy>m)
		continue;
		else if(b[nowx][nowy])
		num++;
	}
	return num;
}

void dfs(int x,int y) 
{
    a[x][y]=nb(x,y);
    if(nb(x,y))
	return;
	else
	{
		for(int i=0;i<8;i++)
		{
			int nowx=x+dr[i][0];
			int nowy=y+dr[i][1];
			if(nowx<0||nowy<0||nowx>n||nowy>m)
			continue;
			if(b[nowx][nowy]||a[nowx][nowy]!=-1) continue;
			dfs(nowx,nowy);
		}
	}
}

int main()
{
	cin>>n>>m>>k>>l;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=-1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			b[i][j]=0;
	for(i=1;i<=k;i++)
	{
		int x1,y1;
		cin>>x1>>y1;
		b[x1][y1]=1;
	}
	while(l--)
	{
		int x,y;
		cin>>x>>y;
		if(a[x][y]>=0)
		continue;
		else if(b[x][y])
		{
			cout<<"You lose"<<endl;
			return 0;
		}
		else
		{
			dfs(x,y);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					cout<<a[i][j]<<' ';
				}
				cout<<endl;
			}
			int flag=1;
			for(i=0;i<n;i++)
				for(j=0;j<m;j++)
				{
					if(a[i][j]==-1&&b[i][j]==0)
					flag=0;
				}
			if(flag)
			{
				cout<<"You win"<<endl;
				return 0;
			}
			else
			cout<<endl;
		}
	}
	return 0;
}
