#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,m,k,l,tot;
int a[25][25];
bool c[25][25];
void qs(int x,int y)
{
	if(x-1>0 && (a[x-1][y]!=-1))a[x-1][y]++;
	if(x+1<=n && (a[x+1][y]!=-1))a[x+1][y]++;
	if(y-1>0 && (a[x][y-1]!=-1))a[x][y-1]++;
	if(y+1<=m && (a[x][y+1]!=-1))a[x][y+1]++;
	if(x-1>0 && y-1>0 && (a[x-1][y-1]!=-1))a[x-1][y-1]++;
	if(x-1>0 && y+1<=m && (a[x-1][y+1]!=-1))a[x-1][y+1]++;
	if(x+1<=n && y-1>0 && (a[x+1][y-1]!=-1))a[x+1][y-1]++;
	if(x+1<=n && y+1<=m && (a[x+1][y+1]!=-1))a[x+1][y+1]++;
}
int flag,xp;
void dfs(int x,int y)
{
	if(c[x][y]==1)return;
	c[x][y]=1;
	if(a[x][y]==0)
	{
	if(x-1>0)dfs(x-1,y);
	if(x+1<=n)dfs(x+1,y);
	if(y-1>0)dfs(x,y-1);
	if(y+1<=m)dfs(x,y+1);
	if(x-1>0 && (y-1>0))dfs(x-1,y-1);
	if(x-1>0 && (y+1<=m))dfs(x-1,y+1);
	if(x+1<=n && (y-1>0))dfs(x+1,y-1);
	if(x+1<=n && (y+1<=m))dfs(x+1,y+1);
	}
}
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		x++;y++;
		a[x][y]=-1;
		qs(x,y);
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;*/
	while(l--)
	{
		int x,y;
		cin>>x>>y;
		x++;y++;
		if(a[x][y]==-1)
		{
			flag=1;
			break;
		}
		if(c[x][y]==1)continue;
		if(c[x][y]==0)
		{
			dfs(x,y);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(c[i][j]==1)cout<<a[i][j]<<" ";
				else
				{
				cout<<-1<<" ";
				if((a[i][j]!=-1))xp=1;
				}
			}
		if(i!=0)cout<<endl;
		}
		if(xp==0)
		{
			cout<<"You win"<<endl;
			return 0;
		}
		else{
			xp=0;
			cout<<endl;
		}
		}
	}
	if(flag==1)
	{
		cout<<"You lose"<<endl;
		return 0;
	}
	return 0;
}

