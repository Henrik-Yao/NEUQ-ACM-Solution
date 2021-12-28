#include<bits/stdc++.h>
using namespace std;

int a[2005][2005]={0};
int m,n;
int ans = 0;
void solve(int x, int y)
{
	if(x<1||x>m||y<1||y>n||a[x][y]==0)
        return;
	a[x][y]=0;
	solve(x+1,y);
	solve(x-1,y);
	solve(x,y+1);
	solve(x,y-1);
}

int main()
{

	cin>>m>>n;

	for(int i=1;i<=m;i++)
	{
		for(int j =1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=m;i++)
    {
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1)
            {
				solve(i,j);
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}
