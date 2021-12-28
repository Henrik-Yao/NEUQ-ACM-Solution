#include<iostream>
#include<map>
using namespace std;

int graph[100][100];

void dfs(int x,int y)
{
	if(!graph[x][y])
	{
        return ;
    }
	graph[x][y]=0;

	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
int main()
{
	int n,m;
    int total = 0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
	    {
            cin>>graph[i][j];
        }
    }
	
	for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=m;j++)
        {
            if(graph[i][j]==1)
            {
                dfs(i,j);
                total++;
            }
        }
    }
	cout<<total;
}