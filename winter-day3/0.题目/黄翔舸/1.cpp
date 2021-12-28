#include<bits/stdc++.h>
using namespace std;

struct node
{
	int from;
	int to;
	int weight;
};

bool cmp(node a, node b)
{
	if (a.from != b.from)
		return a.from < b.from;
	return a.to < b.to;
}

node noder[20005];
int counts[20005];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> noder[i].from >> noder[i].to >> noder[i].weight;
		counts[noder[i].from]++;
	}

	sort(noder, noder + m, cmp);
	// ¥Ú”°
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (counts[i] == 0) continue;
		int sum = counts[i];
		printf("%d:", noder[cnt].from);
		for (int j = 0; j < sum; ++j)
		{
			printf("(%d,%d,%d)", noder[cnt].from, noder[cnt].to, noder[cnt].weight);
			cnt++;
		}
		cout << endl;
	}

	return 0;
}
