#include <bits/stdc++.h>
using namespace std;
int point[1000010][2];
int path[1000010][2];
int mp[1001][1001];
int ans[1001][1001];
int der[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
int m,n,x1,y,x2,y2,now,now_ans;
void dfs(int u,int v){
	if(u==x2&&v== y2)
    {
		for(int i=0;i<now;i++)
        {
			path[i][0] = point[i][0];
			path[i][1] = point[i][1];
			now_ans = now;
		}
		return;
	}
	for(int k=0;k<4;k++)
    {
		int xx = u + der[k][0];
		int yy = v + der[k][1];
		if(xx<1||xx>m||yy<1||yy>n||mp[xx][yy]==-1||ans[xx][yy]<=ans[u][v]+mp[xx][yy])
            continue;
		point[now][0]=xx;
        point[now][1]=yy;
		ans[xx][yy]=ans[u][v]+mp[xx][yy];
		now++;
		dfs(xx,yy);
		now--;
	}
}
int main()
{
	cin>>m>>n;;
	cin>>x1>>y>>x2>>y2;
	for(int i=0;i<m;i++)
    {
		for(int j=0;j<n;j++)
        {
	        int data;
	        cin>>data;
	        mp[i][j]=data;
	    }
    }
	for(int i=1;i<=m-2;i++)
		for(int j=1;j<=n-2;j++)
			ans[i][j]=65535;
	ans[x1][y]=mp[x1][y];
	point[now][0]=x1;
    point[now][1]=y;
	now++;
	dfs(x1,y);
	for(int i=now_ans-1;i>=0;i--)
    {
		cout<<"("<<path[i][0]<<" "<<path[i][1]<<")";
	}
	return 0;
}
