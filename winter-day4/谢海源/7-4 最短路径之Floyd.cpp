#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 1e6;
int g[maxn][maxn];
int path[maxn][maxn];
int n, m;
void floyd()//求最短
{
	for (int k = 0; k < n; k++)//断点
	{
		for (int i = 0; i < n; i++)//起点
		{
			if (g[i][k] == INF) continue;
			for (int j = 0; j < n; j++)//终点
			{
				if (g[i][j] > g[i][k] + g[k][j])
				{
					g[i][j] = g[i][k] + g[k][j];
					path[i][j]=k;
				}
			}
		}
	}
}
void put(int a,int b)
{
	if(path[a][b]==INF) return;
	put(a,path[a][b]);
	cout<<path[a][b]<<"->";
	put(path[a][b],b);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(i==j) g[i][j] = 0;
			else g[i][j] = INF;//默认距离为无穷大
			path[i][j]=INF;
		}
	}
	int a, b, c;
	for (int i = 0; i < m; i++)//m行
	{
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = c;//邻接矩阵创建图
	}
	floyd();
	int x,y;
	for (int i = 0; i < 2; i++)
	{
		scanf("%d%d", &x, &y);
		cout << x << "->";
		put(x,y);
		cout << y << ":";
		if (g[x][y] != INF) cout << g[x][y] << endl;
		else
		{
			cout << "-1" << endl;
		}
	}
	int sta=0, end=0, maxx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(g[i][j]>maxx && g[i][j]<INF)
			{
				maxx=g[i][j];
				sta=i,end=j;
			}
		}
	}
	cout << sta << "->";
	put(sta,end);
	cout << end << ":" << g[sta][end];
	return 0;
}