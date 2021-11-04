#include<bits/stdc++.h>
using namespace std;
int m,n,k,s,d;
const int M=101;
bool a[M];//定义一个bool型判断是否为安全城市 
int w[M][M],dis[M],flag=0,vis[M];
void dfs(int s); 
int main()
{
	cin>>m>>n>>k;
	for(int i=0;i<n;i++)
	{
		int city;
		cin>>city;
		a[city]=1;//标记1安全城市 
	}
	memset(w,0,sizeof(w));
	for(int i=1;i<=k;i++)
	{
		int u,v;
		cin>>u>>v;
		w[u][v]=1;//标记桥 
		w[v][u]=1;
	}
	cin>>s>>d;
	if(!a[d])//判断目的城市是否安全 
	{
		cout<<"The city "<<d<<" is not safe!";
		return 0;
	}
	dfs(s);
	if(flag==0)
	cout<<"The city "<<d<<" can not arrive safely!";
	else
	cout<<"The city "<<d<<" can arrive safely!";
}
void dfs(int s)
{
	 if(s==d) //初始点和终点一致时 
	 {
	 	flag=1;
	 	
	 	return;
	 }
	 for(int i=0;i<m;i++)
	 {
	 	if(!a[i]||vis[i]||w[s][i]==0) continue;
	 	vis[i]=1;
	 	dfs(i);
	 	vis[i]=0;
	 }
	 return;
}
