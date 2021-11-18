#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string.h>
#include<string>
#include<cstdio>
using namespace std;
vector<int>V[20001];
set<int>S;
int n, e;
int visited[20001]={0};
void dfs(int n)
{
	visited[n] = 1;
	cout << n << " ";
	int i, maxn[51];
	for (i = 0; i < V[n].size(); i++)
	{
		maxn[i] = V[n][i];
	}
	sort(maxn, maxn + V[n].size());
	for (i = 0; i < V[n].size(); i++)
	{
		if (!visited[maxn[i]]) dfs(maxn[i]);
	}
}
int main()
{
	int i, a, b;
	cin >> n >> e;
	for (i = 0; i < e; i++)
	{
		cin >> a >> b;
		V[a].push_back(b);
		//V[b].push_back(a);
	}
    for(i=0;i<n;i++)
    {
        if(!visited[i]) dfs(i);
    }
	return 0;
}