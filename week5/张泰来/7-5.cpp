#include <bits/stdc++.h>
using namespace std;
vector <int> v[50005];
int n,k;
int a[50005];
bool vis[50005];
bool in(int x)
{
	return x >= 0 && x < n;
}
bool dfs(int x)
{
	if (!a[x]) return true;
	vis[x] = 1;
	for (int i = 0;i < v[x].size(); i++)
	{
		int next = v[x][i];
		if (vis[next]) continue;
		if (dfs(next)) return true;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n; i++)
	{
		scanf("%d",a + i);
	}
	for (int i = 0;i < n; i++)
	{
		int x = i + a[i];
		int y = i - a[i];
		if (in(x)) v[i].push_back(x);
		if (in(y)) v[i].push_back(y);
	}
	scanf("%d",&k);
	if (dfs(k))
	{
		printf("True\n");
	} else {
		printf("False\n");
	}
	return 0;
}
