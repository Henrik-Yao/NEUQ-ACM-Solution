#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n, m, x, y, b[1001][1001], g, sc[100001];//b数组用于判断是否走过（值=-1）以及是在第几次询问时走的。sc数组代表该次询问总步数 
char a1[1001][1001];//用于输入 
void ddd(int x1, int y1, int z, int xc)//四个参数分别为横坐标、纵坐标、当前的值（0或1）、xc表示是第几次询问 
{
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || b[x1][y1] != (-1) || a1[x1][y1] - '0' != z) return;
	//退出条件：1、越界；2、已访问过（b[i][j]!=-1);3、当前的值与上一个值一样
	//（因为在下面的递归中条件设为!z（即不一样，0变成1,1变成0） ,在这里再否定一下，双重否定为肯定，就是一样！ 
	b[x1][y1] = xc;//标记该点已经被第xc次询问走过 
	sc[xc]++; //第xc次询问的步数加一步。 
	ddd(x1 - 1, y1, !z, xc);//“!z”表示当前值必须与上一个值不同！ 
	ddd(x1 + 1, y1, !z, xc);
	ddd(x1, y1 - 1, !z, xc);
	ddd(x1, y1 + 1, !z, xc);
}
int main()
{
	//freopen("p1141.in","r",stdin);
	//freopen("p1141.out","w",stdout); 
	memset(b, -1, sizeof(b));  // b数组统一赋初值 
	cin >> n >> m;
	for (int i = 0; i <= n - 1; i++)
		for (int j = 0; j <= n - 1; j++)
			cin >> a1[i][j];
	for (int i = 0; i <= m - 1; i++)
	{
		cin >> x >> y;
		x--; y--;//因为数组默认都是从0开始的，而题目输出给定的要求是“第i行第j列”中的i和j明显从1开始，所以，一开始横纵坐标全部回调1
		//为什么不能直接从第1行第1列开始输入？因为第0行第0列的值不好判断，如果从1行第1列开始输入，那么第0行第0列的初始值不论是什么都与其他格子的值不同，这样就不好判断了 
		if (b[x][y] == -1) ddd(x, y, a1[x][y] - '0', i);//如果这个格子没有被走过，则开始DFS 
		else sc[i] = sc[b[x][y]];	//如果这个格子已经被走过，则直接输出走过的值，因为所有走过的都是相通的。 
	}
	for (int i = 0; i <= m - 1; i++)
	{
		if (i == m - 1)
		{
			cout << sc[i];
		}
		else
			cout << sc[i] << endl;
	}
	return 0;
}

