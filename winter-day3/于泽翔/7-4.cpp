#include<bits/stdc++.h>
using namespace std;
int n, m, ans=0;
bool vis[110][110];

void dfs(int x, int y)
{
	if(x<0||x>=n||y<0||y>=m||!vis[x][y])
		return;
	vis[x][y]=0;
	
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}
int main(void)
{
    cin>>n>>m;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>vis[i][j];
    
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
    		if(vis[i][j])
    			dfs(i, j), ans++;
    cout<<ans;
    
    return 0;
}