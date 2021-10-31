#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};
int n,m;
int ma[1005][1005];
int mapp[1005][1005];
int dis[1005][1005];
int k[1000005][3];
string s;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<=n-1;j++)
		{
			if(s[j]=='0')
			{
				ma[i][j+1]=0;
			}
			else if(s[j]=='1')
			{
				ma[i][j+1]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
	}
	while(m--)
	{
		int ans=1;
		int a,b;
		scanf("%d%d",&a,&b);
		if(mapp[a][b]!=0)
		{
			if(m)printf("%d\n",dis[a][b]);
			else printf("%d",dis[a][b]);
			continue;
		}
		queue<pair<int,int> >q;
		k[ans][1]=a;
		k[ans][2]=b;
		mapp[a][b]=1;
		q.push({a,b});
		while(!q.empty())
		{
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			for(int i=1;i<=4;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&mapp[xx][yy]==0)
				{
					if(ma[xx][yy]!=ma[x][y])
					{
						mapp[xx][yy]=1;
						ans++;
						q.push({xx,yy});
						k[ans][1]=xx;
						k[ans][2]=yy;
					}
				}
			}
		}
		for(int i=1;i<=ans;i++)
		{
			dis[k[i][1]][k[i][2]]=ans;
		}
		if(m)printf("%d\n",dis[a][b]);
		else printf("%d",dis[a][b]);
	}
	return 0;
}
