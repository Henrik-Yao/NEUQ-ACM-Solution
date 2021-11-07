#include <bits/stdc++.h>
using namespace std;
string s[110];
int e[6][4]={0,1, 0,-1, 1,0, -1,0};
int vis[110][110], f[110][110], b[1000100][4], res, n, m;

void dfs(int x,int y)
{
    res++;
    int nx, ny;
    b[res][0]=x,b[res][1]=y;
    for(int i=0;i<4;i++)
    {
        nx=x+e[i][0];
        ny=y+e[i][1];
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&vis[nx][ny]&&s[nx][ny]!=s[x][y]){
            vis[nx][ny]=0;
            dfs(nx,ny);
        }
    }
}
int main(void)
{
	int x, y;
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
		cin>>s[i];
	int svs=sizeof(vis);
	memset(vis, 1, svs);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(vis[i][j])
			{
				vis[i][j]=0;
				res=0;
				dfs(i, j);
				for(int k=1; k<=res; k++)
					f[b[k][0]][b[k][1]]=res;
			}
	while(m--)
	{
		cin>>x>>y;
		cout<<f[x-1][y-1]<<endl;
	}
	
	return 0;
}