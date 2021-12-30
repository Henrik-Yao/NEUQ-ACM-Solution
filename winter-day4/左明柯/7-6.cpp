#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > v1[100005],v2[100005];
int a[100005];
long long dis1[100005],dis2[100005];
bool vis[100005];
int n,m,q,x,t,y,c,d;
struct node {
	int id;
	long long val;
	friend bool operator <(node a,node b)
	{
		return a.val > b.val;
	}
};
struct costs{
	int id,t;
	double k;
	friend bool operator <(costs a,costs b)
	{
		return a.k > b.k;
	}
};
void dijkstra1(int start)
{
	priority_queue <node> pq;
	for (int i = 1;i <= n; i++)
	{
		dis1[i] = 1e15;
	}
	dis1[start] = 0;
	node A = {start,0};
	pq.push(A);
	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();
		int pos = cur.id;
		if (vis[pos]) continue;
		vis[pos] = 1;
		for (int i = 0;i < v1[pos].size(); i++)
		{
			int next = v1[pos][i].first;
			int val = v1[pos][i].second;
			if (dis1[next] > dis1[pos] + val)
			{
				dis1[next] = dis1[pos] + val;
				node A = {next,dis1[next]};
				pq.push(A);
			}
		}
	}
	return;
}
void dijkstra2(int start)
{
	priority_queue <node> pq;
	for (int i = 1;i <= n; i++)
	{
		dis2[i] = 1e15;
	}
	dis2[start] = 0;
	node A = {start,0};
	pq.push(A);
	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();
		int pos = cur.id;
		if (vis[pos]) continue;
		vis[pos] = 1;
		for (int i = 0;i < v2[pos].size(); i++)
		{
			int next = v2[pos][i].first;
			int val = v2[pos][i].second;
			if (dis2[next] > dis2[pos] + val)
			{
				dis2[next] = dis2[pos] + val;
				node A = {next,dis2[next]};
				pq.push(A);
			}
		}
	}
	return;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d%d%d",&x,&y,&c,&d);
		if (x == y) continue;
		v1[x].push_back(make_pair(y,c));
		v2[y].push_back(make_pair(x,d));
	}
	
	dijkstra1(1);
	memset(vis,0,sizeof(vis));
	dijkstra2(n);
	
/*	for (int i = 1;i <= n; i++)
		cout << dis1[i] << " ";
	cout << endl;
	for (int i = 1;i <= n; i++)
		cout << dis2[i] << " ";
	cout << endl;
	*/
	priority_queue <costs> pq;

	for (int i = 1;i <= n; i++)
	{
		scanf("%d",&t);
		if (dis1[i] == 1e15 || dis2[i] == 1e15) continue;
		a[i] = t;
		costs A = {i,t,dis1[i] * 1.0 + dis2[i] * 1.0 / t};
		pq.push(A);
	}
	for (int i = 1;i <= q; i++)
	{
		scanf("%d%d",&x,&t);
		if (dis1[x] < 1e15 && dis2[x] < 1e15) 
		{
			a[x] = t;
			costs A = {x,t,dis1[x] * 1.0 + dis2[x] * 1.0 / t};
			pq.push(A);
		}
		while (!pq.empty())
		{
			costs cur = pq.top();
			if (cur.t == a[cur.id]) break;
			pq.pop();
		}
		costs cur = pq.top();
		long long ans = ceil(cur.k);
		printf("%lld\n",ans);
	}
	return 0;
}
