#include<bits/stdc++.h>
using namespace std;
int n,m;int ux,uy,vx,vy;
const int INF=65535;
int ans1=65535,anslen,len;
int dirx[5]={0,-1,0,0,1};
int diry[5]={0,0,1,-1,0};
int prex[2005],prey[2005];
int ansx[2005],ansy[2005];
int mp[2000][2000],vis[2000][2000],ans[2000][2000],dis[2000][2000];
typedef struct P
{
	int x1,y1,w;
};
stack<P> q,temp;
void minn()
{
	anslen=len;
	for(int i=1;i<=len;i++)
	{
		ansx[i]=prex[i];
		ansy[i]=prey[i];
	}
}
void dfs(int x,int y,int step)
{
	if(step>ans1) return;
	if(x==vx&&y==vy)
	{
		if(step<ans1)
		{
			ans1=step;
			minn();
		}
		return;
	}
	for(int i=0;i<=4;i++)
	{
		int xi=x+dirx[i];
		int yi=y+diry[i];
		if(xi>=0&&xi<n&&yi>=0&&yi<n)
		{
			if(mp[xi][yi]!=-1&&!vis[xi][yi])
			{
				prex[++len]=yi;
				prey[len]=xi;
				vis[xi][yi]=1;
				dfs(xi,yi,step+mp[xi][yi]);
				vis[xi][yi]=0;
				len--;
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	cin>>ux>>uy>>vx>>vy;
	prex[uy]=uy;
	prey[ux]=ux;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		cin>>mp[i][j];
	}
	prex[++len]=uy;
	prey[len]=ux;
	dfs(ux,uy,mp[ux][uy]);
	for(int i=anslen;i>=1;i--)
	{
		cout<<"("<<ansy[i]<<" "<<ansx[i]<<")";
	}
}
