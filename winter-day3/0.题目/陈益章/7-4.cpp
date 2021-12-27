#include<iostream>
using namespace std;
int map[105][105],n,m,num=0;
void dfs(int x,int i,int j){
	if(i==n||j==m||x==0||i<0||j<0)
	return ;
	map[i][j]=0;
	dfs(map[i+1][j],i+1,j);
	dfs(map[i-1][j],i-1,j);
	dfs(map[i][j+1],i,j+1);
	dfs(map[i][j-1],i,j-1);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>map[i][j];
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(map[i][j]==1)
		{
			num++;
			dfs(map[i][j],i,j);
		}
	}
	cout<<num;
}
