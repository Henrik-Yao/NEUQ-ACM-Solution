#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n,m;
int be,en;
int d[105][105];
int path[105][105];//记录i到j的最短路径中j的前驱顶点。
int ans;
int anss;
void dfs(int b)
{
	if(be==b)
	{
		cout<<b<<"->";
		return;
	}
	else
	{
		dfs(path[be][b]);
		if(b!=en)cout<<b<<"->";
		else cout<<b<<":";
	}
}
int len(int a,int b,int step)
{
	if(b==a)
	{
		return step;
	}
	else
	{
		return len(a,path[a][b],step+1);
	}
}
int main()
{
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<n;i++)d[i][i]=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);
		path[a][b]=a;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(d[i][j]>=d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
	
	cin>>be>>en;
	if(be==en)
	{
		cout<<be<<"->"<<en<<":0"<<endl;
	}
	else
	{
		if(d[be][en]!=inf)dfs(en);
		else cout<<be<<"->"<<en<<":";
		cout<<(d[be][en]==inf?-1:d[be][en])<<endl;
	}
	
	cin>>be>>en;
	if(be==en)
	{
		cout<<be<<"->"<<en<<":0"<<endl;
	}
	else
	{
		if(d[be][en]!=inf)dfs(en);
		else cout<<be<<"->"<<en<<":";
		cout<<(d[be][en]==inf?-1:d[be][en])<<endl;
	}
	
//*****计算最短路中节点数最多为几，记为ans	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]!=inf)
			{
				int le=len(i,j,1);
				if(le>ans)ans=le;
			}
		}
	}
	
//*******在含有ans个节点的最短路中寻找最长的一条	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]!=inf)
			{
				if(len(i,j,1)==ans)
				{
					if(d[i][j]>anss)
					{
						anss=d[i][j];
						be=i;
						en=j;
					}
				}
			}
		}
	}
	if(d[be][en]!=inf)dfs(en);
	else cout<<be<<"->"<<en<<":";
	cout<<(d[be][en]==inf?-1:d[be][en])<<endl;
	return 0;
}
