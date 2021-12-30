#include<bits/stdc++.h>
using namespace std;
struct tree
{
	int nxt,to,val;
}edge[100010];
int head[20001],tot=0;
typedef pair<int,int> P;
map<P,int> tt;
priority_queue<int,vector<int>,greater<int> >q;
void add(int u,int v,int w)
{
	tot++;
	edge[tot].to=v;
	edge[tot].nxt=head[u];
	edge[tot].val=w;
	head[u]=tot;
}
void bfs(int x)
{
	int flag=0;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		P t;
		t.first=x;
		t.second=v;
		if(tt[t]!=-1)
		{
			flag=1;
			q.push(v);
		}
	}
	if(flag==1)
	cout<<x<<":";
	else
	return;
	while(!q.empty())
	{
		int v=q.top();
		q.pop();
		P l;
		l.first=x;
		l.second=v;
		if(tt[l]==-1) continue;
		printf("(%d,%d,%d)",x,v,tt[l]);
	}
	cout<<endl;
}
int main()
{
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		P t;
		t.first=x,t.second=y;
		tt[t]=z;
		add(x,y,z);	
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int x,y;
		P t;
		cin>>x>>y;
		t.first=x;
		t.second=y;
		tt[t]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(head[i]==0) continue;
		bfs(i);
	}
} 
