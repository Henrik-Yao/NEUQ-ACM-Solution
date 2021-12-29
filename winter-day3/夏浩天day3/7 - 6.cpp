#include <iostream>
#include<algorithm>
using namespace std;

struct T
{
	int u;//顶点1
	int v;//顶点2 
	int w;//权值 
};//结构体存边的信息 
int a[201];

bool cmp(T edge1, T edge2) //排序用的比较
{
	return edge1.w < edge2.w;
}

int find(int x) 
{//查找
	int r = x;
	while (a[r] != r)
		r = a[r];
	return r;
}

int join(int x, int y) 
{//合并 
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) 
	{
		a[fy] = fx;
		return 1;
	}
	return 0;
}

int main()
{
	int n, e;
	while (cin >> n >> e) 
	{
		T tt[101];
		for (int i = 0; i < 201; i++)
			a[i] = i;
		for (int i = 0; i < e; i++) 
			cin >> tt[i].u >> tt[i].v >> tt[i].w;
		sort(tt, tt + e, cmp); //边按权值从小到大排序 
		int cnt = 0, sum = 0; //边数、权值和
		for (int i = 0; i < e; i++) 
		{
			if (join(tt[i].u, tt[i].v)) 
			{//如果顶点u和v不在一个连通图里
				cnt++;
				sum += tt[i].w;
			}
			if (cnt == n - 1) //边数 = 顶点数-1，找到最小生成树 
				break;
		}
		if (cnt == n - 1)
			cout << sum << endl;
		else cout << "There is no minimum spanning tree." << endl;
	}
	return 0;
}

