#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int INF = 65535;
int n,m;
int r[maxn][maxn],s[maxn][maxn];//某个点到起点的消耗最少能量
bool v[maxn][maxn];
const int f[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//移动
struct node
{
	int x,y;
};
bool check(int x,int y)//该点是否合法
{
	if(x<0||x>=n||y<0||y>=n||r[x][y]==-1) return 0;
	return 1;
}
void bfs(int sx,int sy,int ex,int ey)
{
	queue<node>q;
	node sta,next;
	sta.x=sx;sta.y=sy;
	q.push(sta);
	while(!q.empty())
	{
		sta=q.front();
		q.pop();
		v[sta.x][sta.y]=1;//标记已处理
		
		//cout<<sta.x<<" "<<sta.y<<" "<<s[sta.x][sta.y]<<endl;//输出路径
		
		for(int i=0;i<4;i++)
		{
			next.x=sta.x+f[i][0];
			next.y=sta.y+f[i][1];
			if(check(next.x,next.y)&&!v[next.x][next.y])
			{
				v[next.x][next.y]=1;//标记已处理
				s[next.x][next.y]+=s[sta.x][sta.y];//
				q.push(next);
			}
		}
	}
}
void putpath(int ex,int ey,int sx,int sy)//从终点开始打印
{
	printf("(%d %d)",ex,ey);
	if(ex==sx&&ey==sy) return;
	int x,y;
	int ansx=ex,ansy=ey,minn=INF;
	for(int i=0;i<4;i++)
	{
		x=ex+f[i][0];
		y=ey+f[i][1];
		if(minn>s[x][y]&&check(x,y))
		{
			minn=s[x][y];ansx=x;ansy=y;
		}
	}
	putpath(ansx,ansy,sx,sy);
}
int main()
{
	memset(v,0,sizeof(v));
	int stax,stay,endx,endy;
	cin>>n>>m;
	cin>>stax>>stay>>endx>>endy;
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<m;j++)
		{
			scanf("%d",&r[i][j]);
			s[i][j]=r[i][j];//初始化能量
			if(r[i][j]==-1) v[i][j]=1;//标记
		}
	}
	bfs(stax,stay,endx,endy);
	putpath(endx,endy,stax,stay);
	return 0;
}
/*小型测试数据
5 5
1 3 3 3
-1 -1 -1 -1 -1
-1 2 1 1 -1
-1 0 -1 -1 -1
-1 2 1 1 -1
-1 -1 -1 -1 -1
*/