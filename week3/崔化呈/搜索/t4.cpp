#include<bits/stdc++.h>
using namespace std;
int m,n;
int mx[5]={0,-1,0,0,1};
int my[5]={0,0,-1,1,0};
int sh[1100][1100],visit[1100][1100],num[1100][1100];
int kuai[1000100][3];
int main()
{
	cin>>n>>m;
	char a;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a;
			sh[i][j]=(int)a;
		}
	}
	
for(int i=1;i<=m;i++)
	{
		int sum=1;
		int a,b;
		cin>>a>>b;
		if(visit[a][b]!=0)
		{
			if(i==m){cout<<num[a][b];}
			else{cout<<num[a][b]<<endl;}
			continue;
		}
		queue<pair<int,int> >q;
		visit[a][b]=1;
		kuai[sum][1]=a;
		kuai[sum][2]=b;
		q.push({a,b});
		while(!q.empty())
		{
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			for(int j=1;j<=4;j++)
			{
				int xp=x+mx[j];
				int yp=y+my[j];
				if(xp>=1&&xp<=n&&yp>=1&&yp<=n&&visit[xp][yp]==0)
				{
					if(sh[xp][yp]!=sh[x][y])
					{
						visit[xp][yp]=1;
						sum++;
						q.push({xp,yp});
						kuai[sum][1]=xp;
						kuai[sum][2]=yp;
					}
				}
			}
		}
		for(int j=1;j<=sum;j++)
		{
			num[kuai[j][1]][kuai[j][2]]=sum;
		}
		if(i==m){cout<<num[a][b];}
		else{cout<<num[a][b]<<endl;}
	}
	return 0;
}
