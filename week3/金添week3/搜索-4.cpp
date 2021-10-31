#include <bits/stdc++.h>
using namespace std;
int n,m;
int len=0;//find
char zone1[1005][1005];
int zone[1005][1005];//记录地标0，1 
int mark[1005][1005];//记录该地点是否来过 
long long sum[1000025];//记录每一个连通块可以走的地方数目总和 
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};//控制上下左右移动的方向值 
int findx[1005][1005];
bool judge(int remp1,int remp2)
{
	if(remp1>0&&remp1<=n&&remp2>0&&remp2<=n)
	return 1;
	else
	return 0;
}
void search(int remp1,int remp2,int find)
{
	findx[remp1][remp2]=find;
	mark[remp1][remp2]=1;
	sum[find]++;
	for(int i=0;i<4;i++)
	{	
			int zan1=remp1+dx[i];
			int zan2=remp2+dy[i];
			if ((!judge(zan1,zan2)) || mark[zan1][zan2] || (zone[remp1][remp2] == zone[zan1][zan2])) continue;
		    search(zan1,zan2,find);
		
	}
	return;
}
int main()
{	
    n=0;m=0;
    len=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>zone1[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		zone[i][j]=zone1[i][j]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mark[i][j])continue;
			len++;
			search(i,j,len);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(i!=m)
		cout<<sum[findx[x][y]]<<endl;
		else
		cout<<sum[findx[x][y]];
	}
	return 0;
} 
