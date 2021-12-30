#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,tx = -1,ty = -1,ans;
int dis[105][105],inserts[105][105],pre[105];
void deal(int x,int y)
{
	int k = inserts[x][y];
	if (k == -1)
	{
		pre[y] = x;
		return;
	}
	deal(k,y);
	deal(x,k);
	return;
}
void print(int x,int y)
{
	if (x == y)
	{
		printf("%d",x);
		return;
	}
	print(x,pre[y]);
	printf("->%d",y);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n; i++)
	{
		dis[i][i] = 0;
		for (int j = i + 1;j < n; j++)
		{
			dis[i][j] = dis[j][i] = 1e7;
		}
	}
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if (dis[x][y] > z)
		{
			dis[x][y] = z;
			inserts[x][y] = -1;
		}
	}
	for (int k = 0;k < n; k++)
	{
		for (int i = 0;i < n; i++)
		{
			for (int j = 0;j < n; j++)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					inserts[i][j] = k;
				}
			}
		}
	}
	for (int i = 1;i <= 2; i++)
	{
		scanf("%d%d",&x,&y);
		if (x == y) printf("%d->%d:0\n",x,y);
		else {
			if (dis[x][y] == 1e7) printf("%d->%d:-1\n",x,y);
			else {
				memset(pre,0,sizeof(pre));
				deal(x,y);
				print(x,y);
				printf(":%d\n",dis[x][y]);
			}
		}
	}
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			if (dis[i][j] != 1e7 && dis[i][j] > ans)
			{
				ans = dis[i][j];
				tx = i; ty = j;
			}
		}
	}
	memset(pre,0,sizeof(pre));
	if (tx != -1 && ty != -1)
	{
		deal(tx,ty);
		print(tx,ty);
		printf(":%d\n",dis[tx][ty]);
	} else {
		printf("\n");
	}
	return 0;
}
