#include <bits/stdc++.h>
using namespace std;
int graph[51][2];
bool visit[200001];
int n,e;
void search(int remp)
{
	if(visit[remp])
	return;
	visit[remp]=1;
	cout<<remp<<" ";
	int mini=n; 
	for(int i=1;i<=e;i++)
	{
		if(graph[i][0]==remp&&visit[graph[i][1]]==0)//起点相同，终点没有访问过 
		mini=min(mini,graph[i][1]);
	}
	if(mini!=n)//防止一轮寻找下来轮空了，导致mini还是n默认值 
	search(mini);
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>graph[i][0];
		cin>>graph[i][1];
	}	
	for(int i=0;i<n;i++)
	search(i);
	
	return 0;
}
