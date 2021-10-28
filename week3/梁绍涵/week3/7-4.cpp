#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
queue<P> q;
int n,m,a[1000][1000],vis[1000][1000],ans[100000];
int xv[4]={0,0,1,-1};
int yv[4]={1,-1,0,0};
void bfs(int turn,int x,int y)
{
	P a1;
	a1.first=x;
	a1.second=y;
	q.push(a1);
	vis[x][y]=turn;
	int sum=1;
	while(!q.empty())
	{
		P b;
		b=q.front();
		int x1,y1;
		x1=b.first;
		y1=b.second;
		q.pop();
		for(int i=0;i<4;i++)
		{
			int x2,y2;
			x2=x1+xv[i];
			y2=y1+yv[i];
			if(x2>=1&&x2<=n&&y2>=1&&y2<=n&&!vis[x2][y2]&&a[x2][y2]!=a[x1][y1])
			{
                P c;
				c.first=x2;
				c.second=y2;
               	q.push(c);
   	          	sum++;
   	          	vis[x2][y2]=turn;
            }
		}
	}
	ans[turn]=sum;
	return;
}
int main()
{
	cin>>n>>m;
	string c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		for(int j=0;j<n;j++)
		{
			a[i][j+1]=c[j]-'0';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		int xi,yi;
		cin>>xi>>yi;
		if(!vis[xi][yi])	
		bfs(i,xi,yi);
		else
		ans[i]=ans[vis[xi][yi]];
	}	
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
}
