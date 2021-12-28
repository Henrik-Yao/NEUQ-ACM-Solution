#include <bits/stdc++.h>
using namespace std;
int mp[105][105],path[105][105];
int n,m;
void print(int a,int b)
{
	if(path[a][b]==-1)return;
	print(a,path[a][b]);
	cout<<path[a][b]<<"->";
	print(path[a][b],b);
}
int main(){
	cin>>n>>m;
	memset(mp,0x3f,sizeof(mp));
	memset(path,-1,sizeof(path));
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		mp[a][b]=c;
	}
	for(int i=0;i<n;i++)
	mp[i][i]=0;
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(mp[i][j]>mp[i][k]+mp[k][j])
				{
					mp[i][j]=mp[i][k]+mp[k][j];
					path[i][j]=k;
				}
			}
	int x,y;
	for(int i=1;i<=2;i++)
	{
		cin>>x>>y;
		cout<<x<<"->";
		int s=x;
		if(mp[s][y]>1000000)
		{
			cout<<y;
			cout<<":"<<-1<<endl;
			continue;
		}
		print(x,y);
		cout<<y;
		cout<<":"<<mp[x][y]<<endl;
	}
	int maxx=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(mp[i][j]>maxx && mp[i][j]<1000000)
			{
				maxx=mp[i][j];
				x=i,y=j;
			}
		}
	cout<<x<<"->";
	print(x,y);
	cout<<y;
	cout<<":"<<maxx;
    return 0;    
}
