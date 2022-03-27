#include<iostream>
#include<queue>
using namespace std;
int a[50][50],d[50][50];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m,k,l,u,v;
bool check(int x,int y)
{
	if(x>0&&x<=n&&y>0&&y<=m) return 1;
	else return 0;
}
void bfs(int x,int y)
{
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		u=q.front().first;
		v=q.front().second;
		int p=0;
		q.pop();
		if(a[u][v]!=-1) continue;
		a[u][v]=0;
		for(int i=0;i<8;i++)
		{
			int tx=dx[i]+u;
			int ty=dy[i]+v;
			if(check(tx,ty)&&a[tx][ty]==-1)
			{
				if(d[tx][ty]) p++;	
			}
		}
		if(p==0)
		{
			for(int i=0;i<8;i++)
			{
				int tx=dx[i]+u;
				int ty=dy[i]+v;
				if(check(tx,ty)&&a[tx][ty]==-1)
				{
					q.push(make_pair(tx,ty));	
				}
			}
		}
		else a[u][v]=p;
	}
}
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=-1;
	}
	for(int i=0;i<k;i++)
	{
		cin>>u>>v;
		u++;
		v++;
		d[u][v]=1;
	}
	while(l--)
	{
		cin>>u>>v;
		u++;
		v++;
		if(d[u][v]==1)
		{
			 cout<<"You lose";
			 break;
		}
		else if(a[u][v]!=-1) continue;
		else bfs(u,v);
		int p=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==-1) p++;
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		if(p==k) 
		{
			cout<<"You win";
			break;
		}
		cout<<endl;
	}
}
