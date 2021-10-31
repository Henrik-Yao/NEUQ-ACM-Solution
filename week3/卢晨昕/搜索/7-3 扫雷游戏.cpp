#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int dx[10]={0,1,1,1,0,0,-1,-1,-1};
int dy[10]={0,-1,0,1,-1,1,-1,0,1};
int n,m,k,l;
int ma[25][25];//图 
int mapp[25][25];//雷 
bool check()
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ma[i][j]==-1)sum++;
		}
	}
	if(sum==k)return true;
	return false;
}
int v[25][25];//记录是否走过 
void bfs(int a,int b)
{
	queue<pair<int,int> >q;
	q.push({a,b});
	v[a][b]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		int num=0;
		for(int i=1;i<=8;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>=0&&yy>=0&&xx<n&&yy<m)
			{
				if(mapp[xx][yy]==1)num++;
			}
		}
		if(num!=0)ma[x][y]=num;
		else
		{
			ma[x][y]=0;
			for(int i=1;i<=8;i++)
			{
				int xx=x+dx[i];
			    int yy=y+dy[i];
			    if(xx>=0&&yy>=0&&xx<n&&yy<m&&v[xx][yy]==0)
			    {
			    	v[xx][yy]=1;
			    	ma[xx][yy]=0;
			        q.push({xx,yy});
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ma[i][j]=-1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		mapp[a][b]=1;
	}
	while(l--)
	{
		int a,b;
		cin>>a>>b;
		if(mapp[a][b]==1)
		{
			cout<<"You lose";
			return 0;
		}
		else if(v[a][b]==1)continue;
		else
		{
			bfs(a,b);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cout<<ma[i][j]<<" ";
				}
				cout<<endl;
			}
			if(check())
			{
				cout<<"You win";
				return 0;
			}
			else cout<<endl;
		}
	}
	return 0;
}
