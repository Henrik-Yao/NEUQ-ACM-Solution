#include<bits/stdc++.h>
using namespace std;

int a[2005][2005] = {0};
int m,n,ans;

void dfs(int x, int y);

int main()
 {
	cin>>m>>n;

	for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j])
            {
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
}

void dfs(int x, int y)
{
	if(x<1||x>m||y<1||y>n||a[x][y] == 0)
        return;

	a[x][y] = 0;
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);

}

