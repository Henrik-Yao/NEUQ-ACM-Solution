# 7-1双十一
~~~c++
#include <iostream>
#include <cstring>
using namespace std;
int map[200][200];
main()
{
	int v, e;
	while (cin >> v >> e)
	{
		memset(map, 0, sizeof(map));
		for (int t = 0; t < e; t++)
		{
			int i, j;
			cin >> i >> j >> map[i][j];
			map[j][i] = map[i][j];
		}
		for (int k = 0; k < v; k++)
		{
			for (int j = 0; j < v; j++)
			{
				for (int i = 0; i < v; i++)
				{
					if ((map[i][j] > map[i][k] + map[k][j] || map[i][j] == 0) && map[i][k] != 0 && map[k][j] != 0)
					{
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		int sum = 0;
		int minsum = 99999;
		int minn = 0;
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
			{
				sum += map[i][j];
			}
			if (minsum > sum)
			{
				minsum = sum;
				minn = i;
			}
			sum = 0;
		}
		cout << minn<<endl;
	}
}
~~~
# 7-2路由器
~~~c++
#include <iostream>
#include <map>
#include <deque>
using namespace std;
class Rote
{
public:
    deque<int> connect;
    int order;
    bool isdone = 0;
    int deep = 0;
};
Rote list[200];
void bfs(Rote, int);
bool can = 0;
main()
{
    int n, e;
    while (cin >> n >> e)
    {
        for (int p = 0; p < n; p++)
        {
            int a, t, c;
            cin >> a >> t;
            list[a].order = a;
            for (int i = 0; i < t; i++)
            {
                cin >> c;
                list[a].connect.push_back(c);
            }
        }
        for (int p = 0; p < e; p++)
        {
            int x, y;
            cin >> x >> y;
            bfs(list[x], y);

            if (can)
                cout << list[y].deep << endl;
            else
                cout << "connection impossible" << endl;
            for (int i = 0; i < n; i++) //清空
            {
                list[i].isdone = 0;
                list[i].deep = 0;
            }
            can = 0;
        }
        for (int i = 0; i < n; i++) //清空
        {
            list[i].connect.clear();
            list[i].isdone = 0;
            list[i].deep = 0;
        }
    }
}
void bfs(Rote a, int target)
{
    deque<Rote> que;
    que.push_back(a);
    while (que.size() != 0)
    {
        for (auto k = que.begin(); k != que.end(); k++) //遍历当前队列中所有的节点，k
        {
            for (auto it = k->connect.begin(); it != k->connect.end(); it++) //遍历k连接的节点加入队列
            {
                if (list[*it].isdone) //被遍历过
                {
                    continue;
                }
                list[*it].deep = k->deep + 1;
                list[*it].isdone = 1;
                que.push_back(list[*it]);
                if (list[*it].order == target) //发现目标
                {
                    can = 1;
                    return;
                }
            }
            que.pop_front(); //删除k
        }
    }
}
~~~
# 7-3最短路径之Dijkstra
~~~c++
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
~~~
# 7-4最短路径之Floyd
~~~c++
#include <iostream>
#include <cstring>
#include <deque>
#include <set>
using namespace std;
void findpath3(int, int);
int path[200][200];
int map[200][200];
int maxi, maxj, maxn = -1;
set<int> cache;
main()
{
	int v, e;
	cin >> v >> e;

	memset(map, -1, sizeof(map));
	memset(path, -1, sizeof(path));

	for (int t = 0; t < e; t++)
	{
		int i, j;
		cin >> i >> j >> map[i][j];
	}
	for (int i = 0; i < v; i++)
	{
		map[i][i] = 0;
	}
	for (int k = 0; k < v; k++)
	{
		for (int j = 0; j < v; j++)
		{
			for (int i = 0; i < v; i++)
			{
				if ((map[i][j] > map[i][k] + map[k][j] || map[i][j] == -1) && map[i][k] != -1 && map[k][j] != -1)
				{
					map[i][j] = map[i][k] + map[k][j];
					path[i][j] = k;
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << x << "->";
		if (map[x][y] == -1)
		{
			cout << y << ':' << -1 << endl;
			continue;
		}
		findpath3(x, y);
		cout << y << ':' << map[x][y] << endl;
	}
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
		{
			if (maxn < map[i][j])
			{
				maxn = map[i][j];
				maxi = i;
				maxj = j;
			}
		}
	cout << maxi << "->";
	findpath3(maxi, maxj);
	cout << maxj << ':' << maxn;
}
void findpath3(int x, int y)
{
	if (path[x][y] == -1)
	{
		return;
	}
	findpath3(x, path[x][y]);
	cout << path[x][y] << "->";
	findpath3(path[x][y], y);
}
~~~
# 7-5 迷宫变种-最短路径
~~~c++
#include <iostream>
#include <set>
using namespace std;
void dij(int x, int y);
class Node
{
public:
	pair<int, int> front;
	int length = 65535;
	int value;
};
void findpath(int sx, int sy, int ex, int ey);
Node matix[128][128];
bool sign[128][128] = {};
int m, n;
int dis = 0;
main()
{
	cin >> m >> n;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	sx++;
	sy++;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> matix[i][j].value;
			if (matix[i][j].value == -1)
			{
				dis++;
			}
		}
	}
	set<pair<int, int>> sets; //记录已经被开发的区域
	pair<int, int> minn = {sx, sy};
	int min;
	matix[sx][sy].length = 0;
	sign[sx][sy] = 1;
	pair<int, int> now = {sx, sy}; //当前要进行操作的节点
	sets.insert(now);
	int ctrl[] = {1, 0, -1, 0, 1};
	while (sets.size() < m * n - dis)
	{
		min = 65535;
		for (int i = 0, j = 1; i < 4; j++, i++)
		{
			if (sign[now.first + ctrl[i]][now.second + ctrl[j]] || matix[now.first + ctrl[i]][now.second + ctrl[j]].value == -1)
			{
				continue;
			}
			if (matix[now.first + ctrl[i]][now.second + ctrl[j]].length > matix[now.first][now.second].length + matix[now.first + ctrl[i]][now.second + ctrl[j]].value)
			{
				sets.insert({now.first + ctrl[i], now.second + ctrl[j]});
				matix[now.first + ctrl[i]][now.second + ctrl[j]].front = {now.first, now.second};
				matix[now.first + ctrl[i]][now.second + ctrl[j]].length = matix[now.first][now.second].length + matix[now.first + ctrl[i]][now.second + ctrl[j]].value;
			}
		}
		for (auto i = sets.begin(); i != sets.end(); i++)
		{
			if (sign[i->first][i->second])
			{
				continue;
			}
			if (matix[i->first][i->second].length < min && sign[i->first][i->second] != 1)
			{
				min = matix[i->first][i->second].length;
				minn = {i->first, i->second};
			}
		}
		sign[minn.first][minn.second] = 1;
		now = minn;
	}
	cout << '(' << ex << ' ' << ey << ')';
	findpath(sx, sy, ex + 1, ey + 1);
}
void findpath(int sx, int sy, int ex, int ey)
{
	if (sx == ex && sy == ey)
	{
		return;
	}
	cout << '(' << matix[ex][ey].front.first - 1 << ' ' << matix[ex][ey].front.second - 1 << ')';
	findpath(sx, sy, matix[ex][ey].front.first, matix[ex][ey].front.second);
}
~~~
# 森林旅游
我不管我样例对了
~~~c++
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;
void add(int *, int, int, int);
void dij(int *, long long *, int);
int list1[999999], list2[999999], e[999999], ne[999999], w[999999], idx; //链式向前星存储图
int st[99999];
int n, m, q;
int radio[999999];
long long length1[999999], length2[999999]; //添加有权边
main()
{
	cin >> n >> m >> q;
	memset(list1, -1, sizeof(list1));
	memset(list2, -1, sizeof(list2));
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(list1, a, b, c);
		add(list2, b, a, d);
	}
	for (int i = 1; i <= n; i++)
		cin >> radio[i];
	dij(list1, length1, 1);
	dij(list2, length2, n);
	multiset<long long> s;
	for (int i = 1; i <= n; i++)
	{
		//必须要可以连通
		if (length1[i] != 999999 && length2[i] != 999999)
		{
			//此时对于后面需要的代金券兑换的现金需要向上取整,所以要加radio[i]-1
			s.insert(length1[i] + (length2[i] + radio[i] - 1) / radio[i]);
		}
	}
	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		if (length1[a] != 999999 && length2[a] != 999999)
		{
			s.erase(s.find(length1[a] + (length2[a] + radio[a] - 1) / radio[a]));
			radio[a] = b;
			s.insert(length1[a] + (length2[a] + radio[a] - 1) / radio[a]);
		}
		cout << *s.begin() << endl;
	}
}
void add(int *h, int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dij(int *h, long long *length, int start)
{
	memset(length, 0x3f, sizeof length1);
	length[start] = 0;
	memset(st, 0, sizeof st);
	priority_queue<pair<long long ,int>, vector<pair<long long ,int>>, greater<pair<long long ,int>>> heap;
	heap.push({0, start});
	while (heap.size())
	{
		int v = heap.top().second;
		heap.pop();
		if (st[v])
			continue;
		st[v] = true;
		for (int i = h[v]; ~i; i = ne[i])
		{
			int j = e[i];
			if (length[j] > length[v] + w[i])
			{
				length[j] = length[v] + w[i];
				heap.push({length[j], j});
			}
		}
	}
}
~~~