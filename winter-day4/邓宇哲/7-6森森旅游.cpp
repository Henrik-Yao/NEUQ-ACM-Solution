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