#include<bits/stdc++.h>
using namespace std;
int showx[9]={0,1,1,1,0,0,-1,-1,-1};
int showy[9]={0,-1,0,1,-1,1,-1,0,1};
int n,m,k,l;
int sh[30][30],bo[30][30],visit[30][30];
void bfs(int a,int b)
{
	queue<pair<int,int> >q;
	q.push({a,b});
	visit[a][b]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		int num=0;
		for(int i=1;i<=8;i++)
		{
			int xp=x+showx[i];
			int yp=y+showy[i];
			if(xp>=0&&yp>=0&&xp<n&&yp<m)
			{
				if(bo[xp][yp]==1){num++;}
			}
		}
		if(num!=0){sh[x][y]=num;}
		else
		{
			sh[x][y]=0;
			for(int i=1;i<=8;i++)
			{
				int xp=x+showx[i];
				int yp=y+showy[i];
				if(xp>=0&&xp<n&&yp>=0&&yp<m&&visit[xp][yp]==0)
				{
					visit[xp][yp]=1;
					sh[xp][yp]=0;
					q.push({xp,yp});
				}
			}
		}
	}
}
void show()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<sh[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool win()
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(sh[i][j]==-1){sum++;}
		}
	}
	if(sum==k){return 1;}
	else{return 0;}
}
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sh[i][j]=-1;
		}
	}
	int a,b;
	for(int i=1;i<=k;i++)
	{	
		cin>>a>>b;
		bo[a][b]=1;
	}
	for(int i=1;i<=l;i++)
	{
		cin>>a>>b;
		if(bo[a][b]==1)
		{
			cout<<"You lose"<<endl;
			return 0;
		}
		else if(visit[a][b]==1)
		{
			continue;
		}
		else
		{
			bfs(a,b);
			show();
			if(win()){cout<<"You win"<<endl;return 0;}
			else{cout<<endl;}
		}
	}
	return 0;
}
