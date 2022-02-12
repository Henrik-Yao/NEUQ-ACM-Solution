#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 1e6;
int g[maxn][maxn],s[maxn];
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
				}
			}
		}
	}
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(s,0,sizeof(s));
		for (int i = 0; i < n; i++)
		{
			s[i]=INF;
			for (int j = 0; j < n; j++)
			{
				if(i==j) g[i][j] = 0;
				else g[i][j] = INF;//默认距离为无穷大
			}
		}
		int a,b,c;
		for (int i = 0; i < m; i++)//m行
		{
			scanf("%d%d%d", &a, &b, &c);
			g[a][b]=c;//邻接矩阵创建图
			g[b][a]=c;
		}
		floyd();
		for(int i=0;i<n;i++)//处理n个作为起点的情况
		{
			for(int j=0;j<n;j++)
			{
				if(g[i][j]==INF)continue;
				s[i]+=g[i][j];
			}
			if(s[i]!=INF) s[i]-=INF;
			//cout<<s[i]<<endl;
		}
		int sta=0;
		for (int i = 0; i < n; i++)
		{
			if(s[i]<s[sta]&&s[i]!=INF)
			{
				sta=i;
			}
		}
		cout<<sta<<endl;
	}
	return 0;
}