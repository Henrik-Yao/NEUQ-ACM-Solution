#include <iostream>
#include<string.h>
using namespace std;
int n, m, x, y, z;
int cx = -1, cy = -1;
int ans;
int dis[105][105], ins[105][105], p[105];
void deal(int x, int y)
{
	int k = ins[x][y];
	if (k == -1)
	{
		p[y] = x;
		return;
	}
	deal(k, y);
	deal(x, k);
	return;
}
void out(int x, int y)
{
	if (x == y)
	{
		printf("%d", x);
		return;
	}
	out(x, p[y]);
	printf("->%d", y);
	return;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		dis[i][i] = 0;
		for (int j = i + 1; j < n; j++)
		{
			dis[i][j] = 9999999;
			dis[j][i] = 9999999;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		if (dis[x][y] > z)
		{
			dis[x][y] = z;
			ins[x][y] = -1;
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dis[i][k] + dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					ins[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= 2; i++)
	{
		cin >> x >> y;
		if (x == y) printf("%d->%d:0\n", x, y);
		else 
		{
			if (dis[x][y] == 9999999) printf("%d->%d:-1\n", x, y);
			else
			{
				memset(p, 0, sizeof(p));
				deal(x, y);
				out(x, y);
				printf(":%d\n", dis[x][y]);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dis[i][j] != 9999999 && dis[i][j] > ans)
			{
				ans = dis[i][j];
				cx = i; cy = j;
			}
		}
	}
	memset(p, 0, sizeof(p));
	if (cx != -1 && cy != -1)
	{
		deal(cx, cy);
		out(cx, cy);
		printf(":%d\n", dis[cx][cy]);
	}
	else 
		printf("\n");
	return 0;
}