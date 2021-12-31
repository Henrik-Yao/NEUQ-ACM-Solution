#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
bool flag=true;
int chu[22][22],open[22][22],result[22][22];
void sao(int x,int y)
{
	if(flag==false)
	return ;
	if(chu[x][y]==1)
	{
		flag=false;
		return ;
	}
	if(open[x][y]==1)
	return ;
	open[x][y]=1;
	int num=chu[x-1][y-1]+chu[x-1][y]+chu[x][y-1]+chu[x][y+1]+chu[x+1][y]+chu[x-1][y+1]+chu[x+1][y-1]+chu[x+1][y+1];
	result[x][y]=num;
	if(num==0)
	{
		if(open[x-1][y-1]==0&&x-1>=1&&y-1>=1)
		sao(x-1,y-1);
		if(open[x][y-1]==0&&y-1>=1)
		sao(x,y-1);
		if(open[x-1][y]==0&&x-1>=1)
		sao(x-1,y);
		if(open[x+1][y-1]==0&&x+1<=n&&y-1>=1)
		sao(x+1,y-1);
		if(open[x-1][y+1]==0&&x-1>=1&&y+1<=m)
		sao(x-1,y+1);
		if(open[x+1][y]==0&&x+1<=n)
		sao(x+1,y);
		if(open[x][y+1]==0&&y+1<=m)
		sao(x,y+1);
		if(open[x+1][y+1]==0&&x+1<=n&&y+1<=m)
		sao(x+1,y+1);
	}
}
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	result[i][j]=-1;
	for(int i=1;i<=k;i++)
	{
		int p,q;
		cin>>p>>q;
		chu[p+1][q+1]=1;
	}
	for(int i=1;i<=l;i++)
	{
		int p,q;
		cin>>p>>q;
		int flagg=0;
		if(open[p+1][q+1]==0)
		flagg=1;
		sao(p+1,q+1);
		if(flag&&flagg==1)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				cout<<result[i][j]<<" ";
				cout<<endl;
			}
			if(i!=l)
			cout<<endl;
		}
		else if(!flag)
		{
			cout<<"You lose";
			return 0;
		}
	}
	int num=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(result[i][j]==-1)
	num++;
	if(num==k)
	cout<<"You win";
	else
	cout<<endl;
}
