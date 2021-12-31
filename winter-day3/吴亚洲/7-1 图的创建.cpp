#include<bits/stdc++.h>
using namespace std;
struct _map
{
	int x;
	int y;
	int w;
}edge[20005];
bool comp(_map x,_map y)
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
	int n,e;
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	cin>>edge[i].x>>edge[i].y>>edge[i].w;
	sort(edge+1,edge+e+1,comp);
	for(int i=1;i<=e;i++)
	{
		int temp=edge[i].x,t=i;
		while(edge[i].x==temp)
		i++;
		cout<<edge[i-1].x<<":";
		for(int j=t;j<i;j++)
		cout<<"("<<edge[j].x<<","<<edge[j].y<<","<<edge[j].w<<")";
		cout<<endl;
		i--;
	}
}
