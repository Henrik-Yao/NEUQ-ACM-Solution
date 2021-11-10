#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
bool vis[50001];
int n;
int m[50001];
int pd;//不能成功
void dfs(int ss)
{
	if (pd)return;
	if (ss >= n || ss < 0 || vis[ss])return;
	if (!m[ss]) { pd = 1; return; }
	vis[ss] = 1;
	dfs(ss + m[ss]); dfs(ss - m[ss]);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)cin >> m[i];
	int start; cin >> start;
	dfs(start);
	if (pd)cout << "True";
	else cout << "False";
}