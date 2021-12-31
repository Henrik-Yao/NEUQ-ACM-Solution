#include<bits/stdc++.h>
using namespace std;
int G[100][100];
int n,e; 
const int inf=9999;
int root,goal;
int d[100];
bool vis[100]={false};
int pre[100];
int sum=0;
void dij(int s)
{
	fill(d,d+100,inf); 
	d[s]=0;
	for(int i=0;i<n;i++)
          pre[i]=i;
     for(int i=0;i<n;i++)
	{
		int u=-1;
		int MIN=inf;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<MIN)
			{
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1)
		  return;
		vis[u]=true;
	for(int v=0;v<n;v++)
	{
		 if(vis[v]==false&&G[u][v]!=inf&&d[u]+G[u][v]<d[v])
		    {
		    	d[v]=d[u]+G[u][v];
		    	pre[v]=u;
			}
	}
	 } 
	
 } 
void DFS(int s,int v,int sum){
	if(v==s) {
	  	cout<<s;
		  return; 
	  }
	  sum+=G[pre[v]][v];
	  DFS(s,pre[v],sum);
	  cout<<"-->"<<v;
}
int main()
{
	for(int i=0;i<100;i++)
	  for(int j=0;j<100;j++)
	    G[i][j]=9999;
	cin >>n>>e;
	for(int i=0;i<e/2;i++)
	  {
	  	int a,b,c;
	  	cin >>a>>b>>c;
	  	G[a][b]=c;
	  	G[b][a]=c;
	  }

	  cin>>root>>goal;
	if(root==goal)
    {
         cout<<root<<"-->"<<root<<":"<<0;
    return 0;
    }
	dij(root);
	DFS(root,goal,sum);
	  cout<<":"<<d[goal];
 } 


 

