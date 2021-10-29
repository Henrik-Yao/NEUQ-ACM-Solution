#include<bits/stdc++.h>
using namespace std;
struct node {
	int to,next;
}p[250005];
int head[505],d[505];
bool vis[505];
int n,m,a,b,s1,s2,ans,cnt;
bool flag = 1;
inline void add(int u,int v)
{
	p[++cnt].to = v;
	p[cnt].next = head[u];
	head[u] = cnt;
	return;
}
inline int dfs(int x)
{
	if (vis[x])	return d[x];
	vis[x] = 1;
	if (!head[x])
	{
		flag = 0;
		return 0;
	}
	for (register int i = head[x];i;i = p[i].next)
	{
		int next = p[i].to;
		d[x] += dfs(next);
	}
	return d[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for (register int i = 1;i <= m; i++)
	{
		scanf("%d%d",&s1,&s2);
		add(s1,s2);
	}
	scanf("%d%d",&a,&b);
	d[b] = 1;
	vis[b] = 1;
	printf("%d ",dfs(a));
	if (flag) printf("Yes\n");
	else printf("No\n");
	return 0;
}
