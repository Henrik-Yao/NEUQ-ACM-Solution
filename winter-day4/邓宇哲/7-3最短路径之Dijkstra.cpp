#include <iostream>
#include <map>
#include <deque>
using namespace std;
class Node
{
public:
	int value;
	int front;
	int length = 99999;
	map<int, int> connect; // first:节点下标，second:路径权重
	bool isdone = 0;
} list[20];
bool sign[20];
int v, e;
void dij(int);
void findpath(int, int);
main()
{

	cin >> v >> e;
	for (int i = 0; i < e / 2; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		list[a].value = a;
		list[b].value = b;
		list[a].connect[b] = c;
		list[b].connect[a] = c;
	}
	int n, m;
	cin >> n >> m;
	if (n == m)
	{
		cout << n << "-->" << m << ':' << 0;
	}
	else
	{
		dij(n);
		findpath(n, m);
		cout << m << ':' << list[m].length;
	}
}
void dij(int s)
{

	int minn = 0;//保存最小的节点
	int num = 0;//保存最小的路径长度
	list[s].length = 0;//对起点长度先标记为0
	sign[s] = 1;//不进行比较的标记
	deque<int> que;
	que.push_back(s);
	while (que.size() != 0)
	{
		int min = 99999;
		for (auto i = list[*que.begin()].connect.begin(); i != list[*que.begin()].connect.end(); i++)//对当前最小的节点进行子节点遍历
		{
			if (sign[list[i->first].value])//如果已经被记录
			{
				continue;
			}
			if (list[i->first].length > list[*que.begin()].length + i->second)//还可以更小
			{
				list[i->first].length = list[*que.begin()].length + i->second; //计算路程
				list[i->first].front = list[*que.begin()].value;			   //记录下标
			}
		}
		for (int i = 0; i < v; i++)//
		{
			if (list[i].length < min && sign[i] != 1)
			{
				min = list[i].length;
				minn = i;
			}
		}
		sign[minn] = 1;
		num++;
		list[*que.begin()].isdone = 1;
		que.pop_back();
		if (num < v)
			que.push_back(minn);
	}
}
void findpath(int start, int target)
{
	if (target == start)
	{
		return;
	}
	findpath(start, list[target].front);
	cout << list[target].front << "-->";
}