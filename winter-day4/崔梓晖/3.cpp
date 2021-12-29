#include <bits/stdc++.h>
using namespace std;
int t,c,ts,te,a[500][500],rs,re,ci,dis[500],vis[500],ans[500];
const int inf=9999999;
void Dijkstra(int st,int en)
{
	int u,v,cnt=0;
	for(int i=0;i<t;i++)
	{
		dis[i]=a[st][i];
		if(dis[i]!=inf)
		{
			ans[i]=st;
		}
	}
	vis[st]=1;
	int minn;
	for(int i=0;i<t;i++)
	{
		minn=inf;
		for(int j=0;j<t;j++)
		{
			if(vis[j]==0&&dis[j]<minn)
			{
			minn=dis[j];
			u=j;
		    }
		}
	vis[u]=1;
	for(v=0;v<t;v++)
	{
			if(dis[v]>dis[u]+a[u][v])
			{
				dis[v]=dis[u]+a[u][v];
				ans[v]=u;
			}
	}
    }
}
void print(int x,int y)
{
	int s[500],l,k=0;
	l=ans[y];
	cout<<ans[y]<<endl;
	while(l!=x)
	{
		s[k++]=l;
		l=ans[l];
		cout<<ans[l]<<endl;
	}
	cout<<x<<"-->";
	for(int i=k-1;i>=0;i--)
	{
		cout<<s[i]<<"-->";
	}
	cout<<y<<":";
}
int main()
{
	memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
	cin>>t>>c;
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			if(i==j)
			{
			 a[i][j]=0;
			 a[j][i]=0;
		    }
			else 
			{
				a[i][j]=inf;
				a[j][i]=inf;
			}
		}
	}
	for(int i=1;i<=c/2;i++)
	{
		cin>>rs>>re>>ci;
		a[rs][re]=ci;
		a[re][rs]=ci;
	}
	cin>>ts>>te;
	Dijkstra(ts,te);
	print(ts,te);
	cout<<dis[te];
//	cout<<ts<<"-->";
	return 0;
}
