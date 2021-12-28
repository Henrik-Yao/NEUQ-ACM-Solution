#include <bits/stdc++.h>
using namespace std;
vector <int> v[105];
map <int,int> maps;
stack <int> s;
int val[105],dep[105],f[105][9];
int T,t,a,b,root,cnt;
void dfs(int x)
{
	for (int i = 1;i <= 8; i++)
	{
		f[x][i] = f[f[x][i - 1]][i - 1];
	}
	for (int i = 0;i < v[x].size(); i++)
	{
		int next = v[x][i];
		dep[next] = dep[x] + 1;
		f[next][0] = x;
		dfs(next);
	}
	return;
}
int LCA(int x,int y)
{
	if (dep[x] < dep[y]) swap(x,y);
	for (int i = 8;i >= 0; i--)
	{
		if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	}
	if (x == y) return x;
	for (int i = 8;i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt = 0;
		for (int i = 1;i <= 100; i++)
		{
			v[i].clear();
		}
		scanf("%d",&t);
		val[++cnt] = t;
		maps[t] = cnt;
		s.push(cnt);
		while (!s.empty())
		{
			int cur = s.top();
			scanf("%d",&t);
			if (t)
			{
				val[++cnt] = t;
				maps[t] = cnt;
				v[cur].push_back(cnt);
				s.push(cnt);
			} else {
				s.pop();
			}
		}
		scanf("%d",&t);
		scanf("%d%d",&a,&b);
		dfs(1); 
		a = maps[a];
		b = maps[b];
		int k = LCA(a,b);
		printf("%d\n",val[k]);
	}
	return 0;
}