#include <bits/stdc++.h>
using namespace std;
struct node {
	int id,step,type;
};
int n,k,rt,x,y;
char c;
int f[100005][2],gender[100005];
bool vis[100005][2];
bool check(int x,int y)
{
	memset(vis,0,sizeof(vis));
	node a = {x,1,0};
	node b = {y,1,1};
	queue <node> q;
	q.push(a);
	q.push(b);
	vis[x][0] = vis[y][1] = 1;
	while (!q.empty())
	{
		node cur = q.front(); q.pop();
		int t = cur.id;
		if (f[t][0] >= 0)
		{
			if (vis[f[t][0]][1 - cur.type]) 
			{
				return true;
			}
			vis[f[t][0]][cur.type] = 1;
			if (cur.step < 4)
			{
				node f1 = {f[t][0],cur.step + 1,cur.type};
				q.push(f1);
			}
		}
		if (f[t][1] >= 0)
		{
			if (vis[f[t][1]][1 - cur.type])
			{
				return true;
			}
			vis[f[t][1]][cur.type] = 1;
			if (cur.step < 4)
			{
				node f1 = {f[t][1],cur.step + 1,cur.type};
				q.push(f1);
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d %c %d%d",&rt,&c,&x,&y);
		gender[x] = 0;
		gender[y] = 1;
		if (!f[x][0]) f[x][0] = -1;
		if (!f[x][1]) f[x][1] = -1;
		if (!f[y][0]) f[y][0] = -1;
		if (!f[y][1]) f[y][1] = -1;
		gender[rt] = (c == 'F');
		f[rt][0] = x;
		f[rt][1] = y;
	}
	
	scanf("%d",&k);
	for (int i = 1;i <= k; i++)
	{
		scanf("%d%d",&x,&y);
		if (gender[x] == gender[y]) printf("Never Mind\n");
		else if (check(x,y)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
