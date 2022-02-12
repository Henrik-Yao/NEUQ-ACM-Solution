#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,pos;
long long ans;
long long dis[105][105];
int main()
{
	while (scanf("%d%d",&n,&m) != EOF)
	{
		ans = 1e9;
		for (int i = 0;i < n; i++)
		{
			dis[i][i] = 0;
			for (int j = i + 1;j < n; j++)
			{
				dis[i][j] = dis[j][i] = 1e9;
			}	
		}
		for (int i = 1;i <= m; i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			dis[y][x] = dis[x][y] = min(dis[x][y],1ll * z);
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
		for (int i = 0;i < n; i++)
		{
			int sum = 0;
			for (int j = 0;j < n; j++)
			{
				sum += dis[i][j];
			}
			if (sum < ans)
			{
				ans = sum;
				pos = i;
			}
		}
		printf("%d\n",pos);
	}
	return 0;
} 

