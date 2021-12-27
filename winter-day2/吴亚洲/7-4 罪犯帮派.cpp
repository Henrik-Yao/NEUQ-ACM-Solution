#include<bits/stdc++.h>
using namespace std;
int f[1005]={};
bool vis[1005];
int num=0;
int find(int x)
{
	if(x!=f[x])
	return f[x];
	else
	return x;
}
void Union(int x,int y)
{
	if(f[x]!=f[y])
	f[y]=find(x);
}
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	f[i]=i;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		Union(x,y);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(f[x]==f[y])
		cout<<"In the same gang."<<endl;
		else
		cout<<"In different gangs."<<endl;
	}
	for(int i=1;i<=n;i++)
	if(!vis[f[i]])
	{
		vis[f[i]]=true;
		num++;
	}
	cout<<num<<endl;
}
