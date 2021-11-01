#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
queue<P> q;
const int M=1005,N=100000;
int n,m,a[M][M],vis[M][M],answer[N];
int xv[4]={0,0,1,-1};
int yv[4]={1,-1,0,0};
void bfs(int turn,int x,int y); 
int main()
{
	cin>>n>>m;
	string c;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		for(int j=0;j<n;j++)
		{
			a[i][j+1]=c[j]-'0';//标记 
		}
	}
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		if(!vis[q][w])	//判断每一次的能处理的次数 
		bfs(i,q,w);
		else
		answer[i]=answer[vis[q][w]];
	}	
	for(int i=1;i<=m;i++)
	{
		cout<<answer[i]<<endl;
	}
}
void bfs(int turn,int x,int y)
{
	P a1;
	a1.first=x;//第一次 
	a1.second=y;//第二次 
	q.push(a1);
	vis[x][y]=turn;
	int sum=1;
	while(!q.empty())//直到结束 
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
			if(x2>=1&&x2<=n&&y2>=1&&y2<=n&&!vis[x2][y2]&&a[x2][y2]!=a[x1][y1])//判断可否可行 
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
	answer[turn]=sum;
	return;
}
