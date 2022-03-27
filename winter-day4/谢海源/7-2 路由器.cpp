#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 1e6;
int g[maxn][maxn],path[maxn][maxn];
int n, m;
void floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if (g[i][k] == INF) continue;
			for (int j = 0; j < n; j++)//终点
			{
				if(i==j)continue;
				if (g[i][j] > g[i][k] + g[k][j])
				{
					g[i][j] = g[i][k] + g[k][j];
					path[i][j]=k;
				}
			}
		}
	}
}
int find(int a,int b)
{
	if(path[a][b]==INF) return 1;
	return find(a,path[a][b])+1;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(i==j) g[i][j] = 0;
				else g[i][j] = INF;//默认距离为无穷大
				path[i][j]=INF;
			}
		}
		int x,k,y;
		for(int i=0;i<n;i++)//n行
		{
			scanf("%d%d",&x,&k);
			for(int j=0;j<k;j++)//可直接到达的路由器
			{
				scanf("%d",&y);//x到达y
				g[x][y]=1;//邻接矩阵创建图
			}
		}
		floyd();
		for(int i=0;i<m;i++)//m行查询
		{
			scanf("%d%d",&x,&y);
			if(g[x][y]!=INF) cout<<find(x,y)<<endl;
			else cout<<"connection impossible"<<endl;
		}
	}
	return 0;
}