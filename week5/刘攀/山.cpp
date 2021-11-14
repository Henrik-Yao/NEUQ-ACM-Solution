#include<bits/stdc++.h>
using namespace std;
int n, m, sum;
int a[2010][2010];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x, int y)
{
    a[x][y] = 0;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!a[nx][ny]) continue;
        dfs(nx, ny);
    }
}
int main()
{
	cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
         cin>>a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(!a[i][j]) continue;
            dfs(i, j);
            sum++;
        }
    cout<<sum;
    return 0;
}
