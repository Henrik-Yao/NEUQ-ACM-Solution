#include<bits/stdc++.h>
using namespace std;
int m,n,k,to;
bool judge=false;
int safe[101],road[101][101],pass[101];
void dfs(int from)
{
	if(from==to||judge==1)
	{
		judge=1;
		return ;
	}
	for(int i=0;i<m;i++)
	{
		if(pass[i]==0&&road[from][i]==1)
		{
			pass[i]=1;
			dfs(i);
			pass[i]=0;
		}
	}
}
int main()
{
	int from;
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int q;
		cin>>q;
		safe[q]=1;
	}
	for(int i=1;i<=k;i++)
	{
		int p,q;
		cin>>p>>q;
		road[p][q]=1;
		road[q][p]=1;
	}
	cin>>from>>to;
	if(safe[to]==0)
	{
		cout<<"The city "<<to<<" is not safe!";
		return 0;
	}
	dfs(from);
	if(judge)
	cout<<"The city "<<to<<" can arrive safely!";
	else
	cout<<"The city "<<to<<" can not arrive safely!";
}
