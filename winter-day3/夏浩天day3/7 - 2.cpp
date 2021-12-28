#include<iostream>
#include <string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> to[20001];
vector<int> we[20001];



int main() 
{
	int n, e; cin >> n >> e;
	while (e--)
	{
		int a, b, c; cin >> a >> b >> c;
		int xb = 0;
		for (auto lsz : to[a])
			if (lsz > b)xb++;
		to[a].insert(to[a].begin() + xb, b);
		we[a].insert(we[a].begin() + xb, c);
	}
	int k; cin >> k;
	while (k--)
	{
		int a, b; cin >> a >> b;
		int xb = 0;
		for (auto lsz : to[a])
		{
			if (lsz == b)break;
			xb++;
		}
		auto t1 = to[a].begin();
		to[a].erase(t1 + xb);
		auto t2 = we[a].begin();
		we[a].erase(t2 + xb);
	}
	for (int i = 0; i < n; i++)
	{
		if (!to[i].empty())
		{
			printf("%d:", i);
			while (!to[i].empty())
			{
				printf("(%d,%d,%d)", i, to[i].back(), we[i].back());
				to[i].pop_back();
				we[i].pop_back();
			}
			cout << endl;
		}
	}
}
