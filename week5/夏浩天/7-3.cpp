#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;
vector<int> mapp[20001];
int vis[20001];
int n, e, sum;
void dfs(int q1)
{
	if (vis[q1])return;
	cout << q1 << " ";
	vis[q1] = 1;
	for (auto lsz : mapp[q1])
		dfs(lsz);
}
int main() {

	int q1, q2;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> q1 >> q2;
		mapp[q1].push_back(q2);
	}
	for (int i = 0; i < n; i++)
		sort(mapp[i].begin(), mapp[i].end());
	for (int i = 0; i < n; i++)
		dfs(i);
}
