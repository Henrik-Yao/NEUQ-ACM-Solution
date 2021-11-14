#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int a,b,m[2010][2010],res;

void dfs(int x ,int y)//将每座山当作一个块，遍历一个块就加一
{
	m[x][y]=0;
	for(int i=0;i<4;i++)
	{
		int xn=x+dx[i];
		int yn=y+dy[i];
		if(xn<1||yn<1||xn>a||yn>b) continue;
		if(m[xn][yn]==0) continue;
		dfs(xn,yn);
	}
}

int main ()
{
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		for(int j=1 ; j<=b; j++)
		{
			cin>>m[i][j];
		}
	}
	for(int i=1;i<=a;i++)//遍历所有的 
	{
		for(int j=1 ; j<=b; j++)
		{
			if(m[i][j]==0) continue;
			dfs(i,j); 
			res++;
		}
	}
	cout<<res;
	
	return 0;
}