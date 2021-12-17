#include <bits/stdc++.h>
using namespace std;
vector <int> v[1000005];
int n,r,t;
int ans[1000005];
void bfs(int start)
{
	memset(ans,0x3f,sizeof(ans));
	ans[0] = 0;
	queue <int> q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0;i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (next == n - 1)
			{
				ans[n - 1] = ans[cur] + 1;
				return;
			}
			ans[next] = ans[cur] + 1;
			q.push(next);
		}
	}
	return;
}
int main()
{
//	freopen("jump.in","r",stdin);
//	freopen("jump.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i < n; i++)
	{
		scanf("%d",&t);
		if (i + 1ll * t >= n - 1) 
		{
			v[i].push_back(n - 1);
			continue;
		}
		for (int j = r + 1;j <= i + t; j++)
		{
			v[i].push_back(j);
		}
		r = max(r,i + t); 
	}
	bfs(0);
	printf("%d\n",ans[n - 1]);
	return 0;
}
