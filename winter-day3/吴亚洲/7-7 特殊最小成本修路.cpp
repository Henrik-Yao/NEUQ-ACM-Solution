#include<bits/stdc++.h>
using namespace std;
int f[55],num;
struct Edge
{
	int x;
	int y;
	int w;
}edge[55];
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
	int n,v,m,sum,cnt;
	while(cin>>n>>v>>m)
	{
		sum=0,cnt=0,num=0;
		for(int i=0;i<m;i++)
		cin>>edge[i].x>>edge[i].y>>edge[i].w;
		sort(edge,edge+m,comp);
		for(int i=0;i<m;i++)
		f[i]=i;
		int i;
		for(i=0;i<m;i++)
		{
			int rx=f[edge[i].x],ry=f[edge[i].y];
			if(find(rx)!=find(ry))
			{
				if((edge[i].x==v||edge[i].y==v)&&num<2)
				num++;
				else if((edge[i].x==v||edge[i].y==v)&&num==2)
				continue;
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
		cout<<"-1"<<endl;
	}
}
