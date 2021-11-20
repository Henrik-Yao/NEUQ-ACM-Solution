#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
//vector<int> a[20001];
int n,m,vis[20001],cnt=0,head[20001];
struct node
{
	int next,to;
}edge[20001];
void add(int from,int v)
{
	cnt++;
	edge[cnt].next=head[from];
	edge[cnt].to=v;
	head[from]=cnt;
}
void bfs(int x)
{
	vis[x]=1;
	q.push(x);
//	cout<<1;
	while(!q.empty())
	{
		
		int k;
		k=q.top();q.pop();
		cout<<k<<" ";
		for(int i=head[k];i;i=edge[i].next)
		{
			int v=edge[i].to;
			if(!vis[v])
			{
				vis[v]=1;
				q.push(v);
			}
//			cout<<1;
		}
		
	}
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int ui,vi;
		cin>>ui>>vi;
		add(ui,vi);
	}
//	vis[0]=1;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		bfs(i);
	}
	
}
