#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int x;
	int y;
	int w;
	bool exist;
}edge[1005];
bool comp(Edge x,Edge y)
{
	if(x.x<y.x)
	return 1;
	else if(x.x==y.x)
	return x.y<y.y;
	else
	return 0;
}
int main()
{
	int n,e,k;
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>edge[i].x>>edge[i].y>>edge[i].w;
		edge[i].exist=1;
	}
	sort(edge+1,edge+e+1,comp);
	cin>>k;
	while(k--)
	{
		int sx,sy;
		cin>>sx>>sy;
		for(int i=1;i<=e;i++)
		if(edge[i].x==sx&&edge[i].y==sy)
		{
			edge[i].exist=false;
			break;
		}
	}
	for(int i=1;i<=e;i++)
	{
		int temp=edge[i].x,t=i;
		while(edge[i].x==temp)
		i++;
		bool judge=false;
		for(int j=t;j<i;j++)
		if(edge[j].exist)
		judge=1;
		if(!judge)
		{
			i--;
			continue;
		}
		cout<<edge[i-1].x<<":";
		for(int j=t;j<i;j++)
		if(edge[j].exist)
		cout<<"("<<edge[j].x<<","<<edge[j].y<<","<<edge[j].w<<")";
		cout<<endl;
		i--;
	}
}
