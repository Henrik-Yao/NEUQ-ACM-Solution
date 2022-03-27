#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int pre[105];
ll tu[105][105];
int v,e;
ll dis[105];
bool jud[105];
void dfs(int m,int n)
{
	if(m==n) 
	{
		cout<<n;
		return ;
	}
	dfs(m,pre[n]);
	cout<<"-->"<<n;
	
}
int main()
{
	
	cin>>v>>e;
	e=e/2;
	
	memset(tu,0x3f3f3f,sizeof(tu));
	while(e--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		tu[a][b]=c;
		tu[b][a]=c;
	}
	int m,n;
	cin>>m>>n;
	if(m==n) 
	{
		cout<<m<<"-->"<<m<<":"<<0;
		return 0;
	}
	for(int i=0;i<v;i++) pre[i]=i;
	
	int count;
	
	memset(dis,0x3f3f3f,sizeof(dis));
	dis[m]=0;
	for(int t=0;t<v;t++)
	{
		int minn=0x3f3f3f;
		count = -1;
		for(int i=0;i<v;i++)
		{
			
			if(dis[i]<minn&&!jud[i])
		{
			minn=dis[i];
			count=i;
		}
		}
		if(count==-1) return 0;
		jud[count]=1;
		for(int i=0;i<v;i++)
		if(tu[count][i]+dis[count]<dis[i]&&!jud[i]) 
        {
            dis[i]=tu[count][i]+dis[count];
            pre[i] = count ;
        }
        
	}
	dfs(m,n);
	cout<<":"<<dis[n];
	return 0;
} 
