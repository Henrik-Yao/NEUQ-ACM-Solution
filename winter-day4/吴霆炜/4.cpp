#include <bits/stdc++.h>
using namespace std;
#define maxn 102

int n,m,x,y,z,posx = -1,posy = -1,_max;
int mp[maxn][maxn],path[maxn][maxn];
int pre[maxn];//用于记录结点的前驱

void effect(int x,int y);
void print(int x,int y);
int main()
{
	memset(path,-1,sizeof(path));
	scanf("%d%d",&n,&m);
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
		scanf("%d%d%d",&x,&y,&z);
		if (mp[x][y] > z)
		{
			mp[x][y] = z;
		}
	}
	for (int k = 0;k < n; k++)
	{
		for (int i = 0;i < n; i++)
		{
			for (int j = 0;j < n; j++)
			{
				if (mp[i][k] + mp[k][j] < mp[i][j])
				{
					mp[i][j] = mp[i][k] + mp[k][j];
					path[i][j] = k;//记录结点
				}
			}
		}
	}
	int T = 2;
	while(T--)
	{
		scanf("%d%d",&x,&y);
		if (x == y) printf("%d->%d:0\n",x,y);//如果起点等于终点
		else {
			if (mp[x][y] == 1e7) printf("%d->%d:-1\n",x,y);//如果两个点不可达
			else {
				memset(pre,0,sizeof(pre));
				effect(x,y);
				print(x,y);
				printf(":%d\n",mp[x][y]);
			}
		}
	}
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			if (mp[i][j] != 1e7 && mp[i][j] > _max)
			{
				_max = mp[i][j];
				posx = i;
				posy = j;
			}
		}
	}
	memset(pre,0,sizeof(pre));
	if (posx != -1 && posy != -1)
	{
		effect(posx,posy);
		print(posx,posy);
		printf(":%d\n",mp[posx][posy]);
	} else {
		puts("");
	}
	return 0;
}

void effect(int x,int y)
{
	int k = path[x][y];//找到x,y之间的结点，记为k
	if (k == -1)//只要k存在
	{
		pre[y] = x;//x就是y的前驱
		return;
	}
	effect(k,y);//递归查找k到y之间的所有前驱
	effect(x,k);
	return;
}

void print(int x,int y)
{
	if (x == y)//如果起点等于终点，即边界条件
	{
		printf("%d",x);
		return;
	}
	print(x,pre[y]);//递归打印下一个结点
	printf("->%d",y);//打印终点
	return;
}