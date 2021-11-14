#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define w 20005
using namespace std;

int read()
{
	int res = 0, x = 1;
	char c = getchar();
	while (c < '0' || c>'9')
	{
		if (c == '-')
			x = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res * x;
}

struct bianli
{
	int next, to;
}g[w << 1];
int n, m, aa, bb, num, last[w], vis[w];


void dfs(int x)
{
	if (vis[x]) return;
	vis[x] = 1;
	int a[w], tot = 0;
	if (x == 1)
	{
		cout << "0" << " ";
	}
	else
	{
		cout << x - 1 << " ";
	}
	for (int i = last[x]; i; i = g[i].next)
	{
		int v = g[i].to;
		if (!vis[v])
			a[++tot] = v;
	}
	sort(a + 1, a + 1 + tot);
	for (int i = 1; i <= tot; i++)
	{
		dfs(a[i]);
	}
}
void jia(int from, int to);
int main()
{
	n = read(); m = read();
	for (int i = 1; i <= m; i++)
	{
		aa = read(); bb = read();
		aa++; bb++;
		jia(aa, bb);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			dfs(i);
	}
	return 0;
}
void jia(int from, int to)
{
	g[++num].next = last[from];
	g[num].to = to;
	last[from] = num;
}
