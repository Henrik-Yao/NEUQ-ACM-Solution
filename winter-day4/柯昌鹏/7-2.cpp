#include<iostream>
using namespace std;
int main()
{
	int n, e, i, j, k, a, b, w;
	while (cin >> n >> e)//输入路由器的数量
	{
		// if (!n || !e) continue;
		int Dis[201][201] = { 0 };
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Dis[i][j] = 1000;//初始化代表不连通
			}
		}
		
		for (i = 0; i < n; i++)
		{
			cin >> a >> w;//这里的a和w分别代表起点和它的连接的边数
			for (j = 0; j < w; j++)//联通的路由器之间的边权设为一。
			{
				cin >> b;
				Dis[a][b] = 1;
			}
			Dis[n][n] = 0;//表示结点到结点自己的距离为0
		}
		for (i = 0; i < n; i++)//floyd算法
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					if (Dis[j][k] > Dis[j][i] + Dis[i][k]) Dis[j][k] = Dis[j][i] + Dis[i][k];
				}
			}
		}
		for (i = 0; i < e; i++)
		{
			cin >> a >> b;//最后判断
			if (Dis[a][b] != 1000) cout << Dis[a][b] << endl;
			else cout << "connection impossible" << endl;
		}
	}
	return 0;
}