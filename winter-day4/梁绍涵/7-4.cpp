#include<bits/stdc++.h>
using namespace std;
int n,m;
const int INF=0x3f3f3f;
int vis[210],ui,vi;
int edge[210][210],dis[210],path[210][210];
void Floyd()
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=n;j++)
		{
			if (path[i][j]==INF) path[i][j]=-1;
			else path[i][j]=j;
		}
	}
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(edge[i][k]==INF||edge[k][j]==INF) continue;
		if(edge[i][k]+edge[k][j]<edge[i][j])
		{
			edge[i][j]=edge[i][k]+edge[k][j];
			path[i][j] = path[i][k];
		}
	}
}
void getlong()
{
	int max1=-10000,str,end,pos;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) continue;
			if(edge[i][j]>=INF) continue;
//			cout<<i<<" "<<j<<" "<<edge[i][j]<<endl;
			if(edge[i][j]>max1)
			{
				max1=edge[i][j];
				str=i;
				pos=i;
				end=j;
			}
		}
	}
	cout<<str;
	int temp=str;
	while(temp!=end)
	{
		cout<<"->"<<path[temp][end];
		temp=path[temp][end];
	}
	cout<<":"<<edge[str][end];
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	edge[i][j]=INF;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[x][y]=z;
	}
	Floyd();	
//	for(int i=0;i<n;i++)
//	for(int j=0;j<n;j++)
//	cout<<edge[i][j]<<endl;
	for(int i=1;i<=2;i++)
	{
		cin>>ui>>vi;
		if(ui==vi)
		{
			printf("%d->%d:0\n",ui,vi);
			continue;
		}
		int temp=ui,end=vi;
		int flag=0;
		if(edge[ui][vi]!=INF)
		{
			cout<<ui;
			while(temp!=end)
			{
				cout<<"->"<<path[temp][end];
				temp=path[temp][end]; 
			}
			cout<<":"<<edge[ui][vi]<<endl;
		}
		else
		{
			cout<<ui<<"->"<<vi<<":"<<-1<<endl;
		}
	}
	getlong(); 
} 
