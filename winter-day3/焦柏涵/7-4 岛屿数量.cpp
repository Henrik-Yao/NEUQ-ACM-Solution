#include <bits/stdc++.h>
using namespace std;
int is[2002][2002]={0},sum=0,m,n;
int x[4]={-1,0,1,0};//分开 
int y[4]={0,-1,0,1};//分开 
void island(int a,int b)
{
	is[a][b]=0;
	for(int i=0;i<4;i++)
	{
		int a1=a+x[i],b1=b+y[i];
		if(!is[a1][b1]) continue;
		if(a1<1||a1>m||b1<1||b1>n) continue;//注意对应关系 
		island(a1,b1);
	}
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>is[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!is[i][j]) continue;
			sum++;
			island(i,j);
		}
	}
	cout<<sum;
	return 0;
}
