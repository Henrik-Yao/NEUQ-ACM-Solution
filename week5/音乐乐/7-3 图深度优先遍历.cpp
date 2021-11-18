#include<bits/stdc++.h>
using namespace std;
vector<int>t[20010];
int visited[20010];

void dfs(int p)
{
	if(visited[p])
	return;
	visited[p]=1;
	cout<<p<<' ';
	for(int i=0;i<t[p].size();i++)
	{
		if(visited[t[p][i]])
		continue;
		dfs(t[p][i]);
	}
}


int main()
{
	int n,e,i,j;
	cin>>n>>e;
	while(e--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		t[a].push_back(b);
	}
	for(i=0;i<n;i++)
	{
		for(int p=0;p<t[i].size();p++)
		{
			int temp=p;
			for(j=p+1;j<t[i].size();j++)
			{
				if(t[i][j]<t[i][temp])
				temp=j;
			}
			swap(t[i][p],t[i][temp]);
		}
	}
	for(i=0;i<n;i++)
	dfs(i);
	return 0;
}
