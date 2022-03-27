#include<bits/stdc++.h>
using namespace std;
const int M=1000;
const int maxx=999999;
int show[M][M],dis[M],pre[M];
bool vis[M];
void DIJ(int fr,int to,int vn)
{
	vis[fr]=1;
	for(int i=0;i<vn;i++)
	{
		dis[i]=min(dis[i],show[fr][i]);
	}
	int t=fr;
	for(int i=0;i<vn-1;i++)
	{
		int minn=maxx;
		for(int j=0;j<vn;j++)
		{
			if(!vis[j]&&dis[j]<minn)
			{
				minn=dis[j];
				t=j;
			}
		}
		vis[t]=1;
		for(int j=0;j<vn;j++)
		{
			if(dis[t]+show[t][j]<dis[j])
			{
				pre[j]=t;
				dis[j]=dis[t]+show[t][j];
			}
		}
	}
}
int main()
{
	int vn,en;
	scanf("%d%d",&vn,&en);
	en/=2;
	fill(show[0],show[0]+M*M,maxx);
	fill(dis,dis+M,maxx);
	fill(pre,pre+M,-1);
	for(int i=0;i<vn;i++)
	{
		show[i][i]=0;
	}
	int fr,to,w;
	while(en--)
	{
		scanf("%d%d%d",&fr,&to,&w);
		show[fr][to]=w;
		show[to][fr]=w;
	}
	scanf("%d%d",&fr,&to);
	DIJ(fr,to,vn);
	int ans[M];
	int cnt=0;
	int t=to;
	while(t!=-1)
	{
		ans[cnt++]=t;
		t=pre[t];
	}
	printf("%d-->",fr);
	for(int i=cnt-1;i>=1;i--)
	{
		printf("%d-->",ans[i]);
	}
	printf("%d:%d",ans[0],dis[to]);
	return 0;
}
