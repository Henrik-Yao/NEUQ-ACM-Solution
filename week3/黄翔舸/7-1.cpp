#include <iostream>
using namespace std;
#define w 100

typedef struct
{
	int num[w][w];//邻接矩阵
	int dian, bian; //图当前的点数和边数
}Graph;

int main()
{
	int n;//n个安全城市
	Graph G;

	cin >> G.dian >> n >> G.bian;//输入城市的个数、安全城市的个数、路的个数
	int safecity[w];//安全城市
	for (int i = 0; i < n; i++)
	{
		cin >> safecity[i];
	}
	for (int i = 0; i < G.dian; i++)
	{
		for (int j = 0; j < G.dian; j++)
		{
			G.num[i][j] = 0;//初始化邻接矩阵为0
		}
	}
	for (int i = 0; i < G.bian; i++)
	{
		int x, y;
		cin >> x >> y;
		G.num[x][y] = 1;//将有路的城市之间权值变为1
		G.num[y][x] = 1;
	}
	int now, destination, flag = 0;//所在城市和目的地
	cin >> now >> destination;
	for (int i = 0; i < n; i++)
	{
		if (destination == safecity[i])//查询目的地是否为安全城市，做上标记
		{
			flag = 1;
			break;
		}
	}
	if (G.num[now][destination] == 1)
	{
		if (flag)//是安全城市并且有通路
			cout << "The city " << destination << " can arrive safely!";
		else //有通路但是不是安全城市
		{
			cout << "The city " << destination << " is not safe!";

		}
	}
	else
	{
		if (flag)//是安全城市但是没有通路
			cout << "The city " << destination << " can not arrive safely!";
		else cout << "The city " << destination << " is not safe!";//不是安全城市也没有通路
	}
	return 0;
}
