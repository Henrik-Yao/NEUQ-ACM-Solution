#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,z,sx=-1,sy=-1,maxm;
int mp[102][102],path[102][102];
int p[102];
void effect(int x,int y)
{
	int k = path[x][y];
	if (k == -1)
	{
		p[y] = x;
		return;
	}
	effect(k,y);
	effect(x,k);
	return;
}

void print(int x,int y)
{
	if (x == y)
	{
		cout<<x;
		return;
	}
	print(x,p[y]);
	cout<<"->"<<y;
	return;
}
int main()
{
	memset(path,-1,sizeof(path));
	cin>>n>>m;
	for (int i = 0;i < n; i++)
	{
		mp[i][i] = 0;
		for (int j = i + 1;j < n; j++)
		{
			mp[i][j] = mp[j][i] = 1e7;
		}
	}
	for (int i = 1;i <= m; i++)
	{
		cin>>x>>y>>z;
		if (mp[x][y] > z)
		{
			mp[x][y] = z;
		}
	}
	for (int k = 0;k < n; k++)
		for (int i = 0;i < n; i++)
			for (int j = 0;j < n; j++)
				if (mp[i][k] + mp[k][j] < mp[i][j])
				{
					mp[i][j] = mp[i][k] + mp[k][j];
					path[i][j] = k;//记录结点
                }
	int T=2;
	while(T--)
	{
		cin>>x>>y;
		if (x == y)
            printf("%d->%d:0\n",x,y);//如果起点等于终点
		else 
        {
			if (mp[x][y] == 1e7) 
                printf("%d->%d:-1\n",x,y);//如果两个点不可达
			else 
            {
				memset(p,0,sizeof(p));
				effect(x,y);
				print(x,y);
				printf(":%d\n",mp[x][y]);
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(mp[i][j]!=1e7&&mp[i][j]>maxm)
			{
				maxm=mp[i][j];
				sx=i;
				sy=j;
			}
	memset(p,0,sizeof(p));
	if (sx!=-1&&sy!=-1)
	{
		effect(sx,sy);
		print(sx,sy);
		printf(":%d\n",mp[sx][sy]);
	} else {
		puts("");
	}
	return 0;
}


