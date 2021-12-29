#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int n,m;
int ans=inf;
int ma[2005][2005];
int v[2005][2005];
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};
int prex[2005],prey[2005];
int ansx[2005],ansy[2005];
int len;
int anslen;
void minn()
{
	anslen=len;
	for(int i=1;i<=len;i++)
	{
		ansx[i]=prex[i];
		ansy[i]=prey[i];
	}
}
void dfs(int a,int b,int c,int d,int step)
{
	if(step>ans)return;
	if(a==c&&b==d)
	{
		if(step<ans)
		{
			ans=step;
			minn();
		}
		return;
	}
	for(int i=1;i<=4;i++)
	{
		int x=a+dx[i];
		int y=b+dy[i];
		if(x>=0&&x<n&&y>=0&&y<n)
		{
			if(ma[x][y]!=-1&&!v[x][y])
			{
				prex[++len]=y;
				prey[len]=x;
				v[x][y]=1;
				dfs(x,y,c,d,step+ma[x][y]);
				v[x][y]=0;
				len--;
			}
		}
	}
}
int main()
{
	int a,b,c,d;
	cin>>m>>n;
	cin>>a>>b>>c>>d;
	prex[b]=b;
	prey[a]=a;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ma[i][j];
		}
	}
	prex[++len]=b;
	prey[len]=a;
	dfs(a,b,c,d,ma[a][b]);
	for(int i=anslen;i>=1;i--)
	{
		cout<<"("<<ansy[i]<<" "<<ansx[i]<<")";
	}
	return 0;
}
