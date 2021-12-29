#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,cost;
}e[1600];
int f[1600];
int n,m,cnt,sum=0,rx,ry;
bool cmp(edge from,edge to)
{
	return from.cost<to.cost;
}
int find(int x)
{
	if(f[x]==x)
	return x;
	return find(f[x]);
}
int main()
{
	while(cin>>n>>m)
	{
	sum=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].from>>e[i].to>>e[i].cost;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++) f[i]=i;
	int i;
	for(i=1;i<=m;i++)
	{
		int rx=f[e[i].from],ry=f[e[i].to];
		if(find(rx)!=find(ry))
		{
			cnt++;
			rx=find(rx);
			ry=find(ry);
			f[rx]=ry;
			sum+=e[i].cost;
		}
		if(cnt==n-1) break;
		
	}
	if(cnt==n-1) cout<<sum<<endl;
	else cout<<"There is no minimum spanning tree."<<endl;
	
}
	
	
	
} 
