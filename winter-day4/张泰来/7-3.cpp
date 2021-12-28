#include <bits/stdc++.h>
using namespace std;
struct node {
	int to,next,val;
}p[5000005];
int n,m,x,y,z,cnt,s,t;
int pre[50005],head[50005];
long long dis[50005];
bool vis[50005];
void add(int u,int v,int w)
{
	p[++cnt].to = v;
	p[cnt].val = w;
	p[cnt].next = head[u];
	head[u] = cnt;
	return;
}
void dijkstra(int start)
{
	memset(vis,0,sizeof(vis));
	for (int i = 0;i < n; i++)
		dis[i] = 1e17;
	dis[start] = 0;
	for (int i = 1;i <= n; i++)
	{
		long long minn = 1e17;
		int pos;
		for (int j = 0;j < n; j++)
		{
			if (vis[j]) continue;
			if (minn > dis[j])
			{
				minn = dis[j];
				pos = j;
			}
		}
		vis[pos] = 1;
		for (int i = head[pos];i;i = p[i].next)
		{
			int next = p[i].to;
			int val = p[i].val;
			if (dis[pos] + val < dis[next])
			{
				dis[next] = dis[pos] + val;
				pre[next] = pos;
			}
		}
	}
	return;
}
void print(int x)
{
	if (x == s)
	{
		printf("%d",x);
		return;
	}
	print(pre[x]);
	printf("-->%d",x);
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	m /= 2;
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	scanf("%d%d",&s,&t);
	if (s == t) printf("%d-->%d:0\n",s,t);
	else {
		dijkstra(s);
		print(t);
		printf(":%lld\n",dis[t]);
	}
	return 0;
}
