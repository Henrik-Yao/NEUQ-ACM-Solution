#include <algorithm>
#include <iostream>
using namespace std;
class date
{
public:
	int start, end, num = 0;
	int next[128] = {0};
	bool done = 0;
};
bool compare(date a, date b)
{
	return a.start < b.start;
}
void dfs(date *, int);
int deep = 1;
int maxt;
main()
{
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		maxt = 0;
		date node[t];
		for (int j = 0; j < t; j++)
		{
			cin >> node[j].start >> node[j].end;
		}
		sort(node, node + t, compare);
		for (int j = 0; j < t - 1; j++)
		{
			for (int k = j + 1; k < t; k++)
			{
				if (node[k].start >= node[j].end)
				{
					node[j].next[node[j].num++] = k;
				}
			}
		}
		for (int j = 0; j < t; j++)
		{
			dfs(node, j);
		}
		cout << t-maxt<<endl;
	}
}
void dfs(date *node, int n)
{
	maxt = max(maxt, deep);
	node[n].done = 1;
	{
		for (int i = 0; i < node[n].num; i++)
		{
			deep++;
			dfs(node, node[n].next[i]);
			deep--;
		}
	}
}