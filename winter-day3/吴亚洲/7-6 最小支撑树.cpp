#include<bits/stdc++.h>
using namespace std;
int f[1505];
struct Edge
{
	int x;
	int y;
	int w;
}edge[1505];
int find(int x)
{
	if(f[x]==x)
	return x;
	return find(f[x]);
}
bool comp(Edge x,Edge y)
{
	return x.w<y.w;
}
int main()
{
	int n,m,sum,cnt;
	while(cin>>n>>m)
	{
		sum=0,cnt=0;
		for(int i=1;i<=m;i++)
		cin>>edge[i].x>>edge[i].y>>edge[i].w;
		sort(edge+1,edge+1+m,comp);
		for(int i=1;i<=n;i++)
		f[i]=i;
		int i;
		for(i=1;i<=m;i++)
		{
			int rx=f[edge[i].x],ry=f[edge[i].y];
			if(find(rx)!=find(ry))
			{
				sum+=edge[i].w;
				cnt++;
				rx=find(rx);
				ry=find(ry);
				f[rx]=ry;
			}
			if(cnt==n-1)
			break;
		}
		if(cnt==n-1)
		cout<<sum<<endl;
		else
		cout<<"There is no minimum spanning tree."<<endl;
	}
}
