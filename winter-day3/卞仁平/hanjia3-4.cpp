#include <bits/stdc++.h>>
using namespace std;
int s=0;
int a[102][102];
void change(int n,int m)
{
	if(a[n][m]==1) 
	{
		a[n][m]=0;
		for(int x=-1;x<=1;x++)
		for(int y=-1;y<=1;y++)
		if(x*y==0) change(n+x,m+y);
		return ;
	}
	else return ;
}
void he(int n,int m)
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(a[i][j]==1)
	{
		s++;
		change(i,j);
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++) 
        cin>>a[i][j];
	he(n,m);
	cout<<s;
	return 0;
}
