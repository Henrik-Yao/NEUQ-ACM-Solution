#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	x=x*10+(ch^48),ch=getchar();
	return x*f;
} 
int m,n,tot;
bool a[2005][2005],vis[2005][2005];
void dfs(int x,int y)
{
	vis[x][y]=0;
	if(x-1>0 && vis[x-1][y])dfs(x-1,y);
	if(x+1<=m && vis[x+1][y])dfs(x+1,y);
	if(y-1>0 && vis[x][y-1])dfs(x,y-1);
	if(y+1<=n && vis[x][y+1])dfs(x,y+1);
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
			vis[i][j]=a[i][j];
		}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][j] && vis[i][j])
			{
				dfs(i,j);tot++;
			}
		}
	cout<<tot;
	return 0;
}
