#include<bits/stdc++.h>
using namespace std;

int flag[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int a[2010][2010];
int n,m,ans=0;
int p[2010][2010];
struct duilie
{
	int x0;
	int y0;
};
duilie q[4000001];
void bfs(int x,int y)
{
	int front=0,rear=2;
	while(front<rear-1)
	{
		++front;
		x=q[front].x0;
		y=q[front].y0;
		for(int i=0;i<4;++i)
		{
			int x1=x+flag[i][0];
			int y1=y+flag[i][1];
			if(x1<1||y1<1||x1>n||y1>m||!a[x1][y1]||p[x1][y1])
			continue;
			p[x1][y1]=true;
			q[rear].x0=x1;
			q[rear++].y0=y1;
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]&&!p[i][j])
			{
				++ans;
				q[1].x0=i;
				q[1].y0=j;
				bfs(i,j);
			}
	cout<<ans<<endl;
	return 0;
}
