#include<bits/stdc++.h>
using namespace std;
int n,judge;
int flag[100005];
struct people
{
	int f,m,id;
	char gen;
}p[100005];
void dfs(int x,int d)
{
	if(d==6||x<=0)
	return ;
	if(flag[x])
	{
		judge=1;
		return ;
	}
	flag[x]=1;
	dfs(p[x].f,d+1);
	dfs(p[x].m,d+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int idd;
		cin>>idd;
		cin>>p[idd].gen>>p[idd].f>>p[idd].m;
		p[p[idd].f].gen='M';
		p[p[idd].m].gen='F';
	}
	int k;
	cin>>k;
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		if(p[x].gen==p[y].gen)
		{
			cout<<"Never Mind"<<endl;
			continue;
		}
		memset(flag,0,sizeof(flag));
		judge=0;
		dfs(x,1);
		dfs(y,1);
		if(judge)
		cout<<"No"<<endl;
		else
		cout<<"Yes"<<endl;
	}
}
