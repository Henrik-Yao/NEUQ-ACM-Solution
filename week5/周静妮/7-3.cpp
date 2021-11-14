#include<bits/stdc++.h>
using namespace std;
bool vis[20001];
int n,e,xian[51][2];
void bfs(int m)
{
	if(vis[m]) return ;
	vis[m]=1;
	cout<<m<<' ';
	int end=n;
	for(int i=0;i<e;i++)
	{
		if(xian[i][0]==m&&!vis[xian[i][1]]) end=min(xian[i][1],end);
	}
	if(end!=n) bfs(end);
}
int main()
{
	
	cin>>n>>e;
	for(int i=0;i<e;i++) cin>>xian[i][0]>>xian[i][1];
	bfs(0);
	for(int i=1;i<n;i++)
	{
		if(!vis[i]) bfs(i);
	}
	return 0;
}
