#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,id,k;
int dis[205][205];
int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		for (int i = 0;i < n; i++)
		{
			dis[i][i] = 0;
			for (int j = i + 1;j < n; j++)
			{
				dis[i][j] = dis[j][i] = 1e9;
			}	
		}
		for (int i = 1;i <= n; i++)
		{
			scanf("%d%d",&id,&k);
			for (int j = 1;j <= k; j++)
			{
				scanf("%d",&x);
				dis[id][x] = 1;
			}
		}
		for (int k = 0;k < n; k++)
		{
			for (int i = 0;i < n; i++)
			{
				for (int  j = 0;j < n; j++)
				{
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		for (int i = 1;i <= m; i++)
		{
			scanf("%d%d",&x,&y);
			if (dis[x][y] < 1e9) printf("%d\n",dis[x][y]);
			else printf("connection impossible\n");
		}
	}
}
