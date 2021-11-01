#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void dfs(int x,int y,int now,int pos);
int fx[4]={1,0,-1,0};
int fy[4]={0,1,0,-1};
int n,m,x,y;
int wyj[1001][1001],ans[1000001];
char a[1001][1001];
int main()
{memset(wyj,-1,sizeof(wyj));//全部赋值为-1 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];}
	}
	for(int i=1;i<=m;i++)
	{	cin>>x>>y;
		if(wyj[x][y]==-1) {dfs(x,y,a[x][y]-'0',i);}
		else{ans[i]=ans[wyj[x][y]];}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}


void dfs(int x,int y,int now,int pos)
{
	if(x<1||y<1||y>n||x>n||wyj[x][y]!=-1||a[x][y]-'0'!=now)
	return;
		wyj[x][y]=pos;
		ans[pos]++;
		for(int i=0;i<4;i++)
		{ int yy=fy[i]+y;
		  int xx=fx[i]+x;
		  dfs(xx,yy,!now,pos);
		}
}
