#include<iostream> 
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int>v[20020];
int m, temp[20020], mem[20020];

struct edge
{
	int to;
	int next;
	int weight;
}e[20010];

void add(int x, int y, int z)
{
	++m;
	v[x].push_back(m);
	e[m].to = y;
	e[m].next = x;
	e[m].weight = z;
}

int main()
{
	int n, ed, i;
	cin >> n >> ed;
	for (i = 1; i <= ed; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
	}
	for (i = 0; i < n; i++)
	{
		memset(temp, 0, sizeof(temp));
		memset(mem, 0, sizeof(mem));
		if (v[i].size())
		{
			int len = v[i].size();
			for (int j = 0; j < len; j++)
			{
				temp[j] = e[v[i][j]].to;
				mem[temp[j]] = e[v[i][j]].weight;
			}
			sort(temp, temp + len);
			cout << i << ':';
			for (int j = 0; j < len; j++)
			{
				cout << "(" << i << "," << temp[j] << "," << mem[temp[j]] << ")";
			}
			cout << endl;
		}
	}
}