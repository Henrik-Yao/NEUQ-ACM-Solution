#include<bits/stdc++.h> 
using namespace std;
int a[22][22],b[22][22];
int ad[8][2]={0,1,1,0,-1,0,0,-1,1,1,1,-1,-1,1,-1,-1};
int n,m,k,l;
int key(int x,int y);
void dfs(int x,int y) 
{
    a[x][y]=key(x,y);
    if(key(x,y)!=0)
	return;
	else
	{
		for(int i=0;i<8;i++)
		{
			int nowx=x+ad[i][0], nowy=y+ad[i][1];
			if(nowx<0||nowy<0||nowx>n||nowy>m)
			continue;
			if(b[nowx][nowy]||a[nowx][nowy]!=-1) 
			continue;
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
		
