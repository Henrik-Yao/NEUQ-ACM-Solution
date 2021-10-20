#include <iostream>
#include <string.h>
using namespace std;
int x[100000], y[100000], z[1000000];//x,y分别标记道路两端的城市，z来标记该道路是否被封堵
int main()//问题的核心是是否所有的道路都均被封堵。
{
	int m, n, remp, q, a;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];//将该道路的两端城市进行记录
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> remp;
		int flag = 0;
		for (int k = 1; k <= m; k++)
			z[k] = 1;
		for (int j = 0; j < remp; j++)
		{
			cin >> a;
			z[a] = 0;//若攻占这座城市，直接标记为0
		}
		for (int j = 1; j <= n; j++)
		{
			if ((z[x[j]]) && (z[y[j]]))//依次检测之前输入的道路，判断该道路是否被封阻。
			{
				flag = 1;	//该道路畅行无阻！
				break;
			}
		}
		if (flag == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}