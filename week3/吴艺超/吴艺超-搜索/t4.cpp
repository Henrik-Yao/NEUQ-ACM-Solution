#include<bits/stdc++.h>
#define ll long long
#define R register
using namespace std;
inline int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	x=x*10+(ch^48),ch=getchar();
	return x*f;
}
bool a[1100][1100];
int tot,n,m;
int x,y;
bool a1[1100][1100];
int ans[1100][1100];
struct ax{
	int xx;
	int yy;
}ji[1100000];
void dfs(int x,int y,int z)
{
	
	tot++;ji[tot].xx=x;ji[tot].yy=y;
	if(x+1<=n && a[x+1][y]==!z && a1[x+1][y]==0)
	{
		a1[x+1][y]=1;
		dfs(x+1,y,!z);
	}
	if(y+1<=n && a[x][y+1]==!z && a1[x][y+1]==0)
	{
		a1[x][y+1]=1;
		dfs(x,y+1,!z);
	}
	if(x-1>0 && a[x-1][y]==!z && a1[x-1][y]==0)
	{
		a1[x-1][y]=1;
		dfs(x-1,y,!z);
	}
	if(y-1>0 && a[x][y-1]==!z && a1[x][y-1]==0)
	{
		a1[x][y-1]=1;
		dfs(x,y-1,!z);
	}
	return;			
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			char x;
			cin>>x;
			a[i][j]=x^48;
		}	
	while(m--)
	{
		cin>>x>>y;
		if(a1[x][y]==1)
		{
			cout<<ans[x][y]<<endl;
			continue;
		}
//		memset(a1,0,sizeof(a1));
		 tot=0;
		 a1[x][y]=1;
		 dfs(x,y,a[x][y]);
		 cout<<tot;
		 if(m!=0)cout<<endl;
		 for(int i=1;i<=tot;i++)
		 ans[ji[i].xx][ji[i].yy]=tot;
	}
	return 0;
}
